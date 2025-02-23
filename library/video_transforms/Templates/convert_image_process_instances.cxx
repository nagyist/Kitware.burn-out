/*ckwg +5
 * Copyright 2012-2016 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include <vxl_config.h>

#include <video_transforms/convert_image_process.txx>

template class vidtk::convert_image_process<vxl_uint_16, vxl_byte>;
template class vidtk::convert_image_process<vxl_byte, vxl_byte>;
template class vidtk::convert_image_process<float, vxl_byte>;
template class vidtk::convert_image_process<float, double>;
