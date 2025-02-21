/*ckwg +5
 * Copyright 2011-2015 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef thread_util_h_
#define thread_util_h_

#include <string>

namespace vidtk
{

// Names the thread. Returns false if the thread was not renamed (lack of
// platform support or a failure).
bool name_thread(std::string const& name);

}

#endif
