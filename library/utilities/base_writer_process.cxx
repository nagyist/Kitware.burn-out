/*ckwg +5
 * Copyright 2011-2016 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include <utilities/base_writer_process.h>

namespace vidtk
{

base_writer_process::
  base_writer_process(std::string const& _name,  std::string const& type)
    : base_io_process(_name, type)
{
}


base_writer_process::
~base_writer_process()
{
}


// ----------------------------------------------------------------
/** Initialize process.
 *
 *
 */
bool base_writer_process::
initialize_internal()
{
  m_dataGroup.write_header (file_stream());

  return (true);
}


// ----------------------------------------------------------------
/** Open output file.
 *
 * This method handles opening the output file. The file is closed if
 * it is already open.  Also handles open modes for append or
 * overwrite.
 */
void base_writer_process::
  open_file()
{

  if ( this->m_appendFile )
  {
    file_stream().open(this->m_filename.c_str(), std::ofstream::out | std::ofstream::app);
  }
  else
  {
    file_stream().open(this->m_filename.c_str(), std::ofstream::out | std::ofstream::trunc);
  }
}


// ----------------------------------------------------------------
/** Main process step.
 *
 *
 */
int base_writer_process::
  do_file_step()
{
  m_dataGroup.write_object (file_stream());
  return (0);
}


} // end namespace vidtk
