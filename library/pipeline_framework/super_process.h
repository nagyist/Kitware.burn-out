/*ckwg +5
 * Copyright 2010-2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef vidtk_super_process_h_
#define vidtk_super_process_h_

#include <utilities/config_block.h>
#include <utilities/checked_bool.h>
#include <process_framework/process.h>
#include <pipeline_framework/pipeline.h>

#include <string>
#include <vector>


namespace vidtk
{
// This class is a simple container for super_processes
// so that they can be distinguished from processes.
// There is no difference from using this, or process,
// as a parent to inherit from.

class super_process;
class async_pipeline_node;

// ----------------------------------------------------------------
/** \brief Group of processes.
 *
 * This class represents a group of processes connected to a
 * pipeline. A super_process enables hierarchial construction of
 * pipelines by providing a wrapper around a group of processes
 * configured in a local pipeline, allowing the group to be treated as
 * a single process.
 */
class super_process
  : public process
{
public:
  typedef super_process self_type;
  super_process( std::string const& name, std::string const& class_name );
  virtual void create_graphviz( std::vector<std::string> const& /*incoming_edges_*/ ) {};
  virtual ~super_process() {};

  /// Returns the current configuration parameters.
  virtual config_block params() const;

  /// Allows the user to set the configuration parameters.
  virtual bool set_params( config_block const& );

  /// Initializes the module.
  virtual bool initialize();

  /// Reset the process
  virtual bool reset();

  /// cancel all threads in pipeline.
  virtual bool cancel();

  /// Called after each step to log current state (in both sync and async)
  /// This function is called after step in the sync pipeline and after all
  /// outputs are available in the async pipeline.  Log statements should
  /// go here instead of in \c step() because \c step() is not called in the
  /// async case.
  virtual void post_step() {}

  pipeline_sptr get_pipeline() const;

  virtual bool run(async_pipeline_node* parent);

  /// This function is called when the pipeline detects failure in the sp.
  /// It gives the sp a last chance to recover from the failure before
  /// propigating the failure out the the external pipeline.
  virtual bool fail_recover()
  {
    return false;
  }

  void set_print_detailed_report( bool );

protected:
  pipeline_sptr pipeline_;


private:
  friend void delete_super_process_object( super_process* );

};  // class super_process


// ----------------------------------------------------------------
/// Base class for templated \c super_process_pad_impl.
class super_process_pad
  : public process
{
public:
  typedef super_process_pad self_type;

  super_process_pad( std::string const& _name )
    : vidtk::process( _name, "pad" )
  {
  }

  vidtk::config_block params() const
  {
    return vidtk::config_block();
  }

  bool set_params( vidtk::config_block const& )
  {
    return true;
  }

  bool initialize()
  {
    return true;
  }

  bool step()
  {
    return true;
  }

};  // class super_process_pad


// ----------------------------------------------------------------
/// This process is used to safely make connections outside of a super process.
/// A pad is a dummy process used for making connections.  There should be one
/// pad process for each input port and each output port of the super process.
/// These processes should be added to the super process pipeline with
/// \c add_no_execute().  All internal nodes that want the input data should
/// connect to the pad.
template <class T>
class super_process_pad_impl
  : public super_process_pad
{
public:
  typedef super_process_pad_impl<T> self_type;

  super_process_pad_impl( std::string const& _name, const T& init_value = T())
    : vidtk::super_process_pad( _name ),
      value_( init_value ),
      set_called_( false )
  {
  }

  bool step()
  {
    if( !this->set_called_ )
    {
      this->value_ = T();
    }
    this->set_called_ = false;
    return true;
  }

  void set_value( T d )
  {
    this->set_called_ = true;
    this->value_ = d;
  }

  VIDTK_INPUT_PORT( set_value, T );

  T value() const
  {
    return this->value_;
  }

  VIDTK_OUTPUT_PORT( T, value );

private:
  T value_;
  bool set_called_;
};  // class super_process_pad_impl

} // end namespace vidtk

#endif // vidtk_super_process_h_
