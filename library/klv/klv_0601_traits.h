/*ckwg +5
 * Copyright 2012-2015 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef VIDTK_KLV_0601_TRAITS_H_
#define VIDTK_KLV_0601_TRAITS_H_


#include <klv/klv_0601.h>
#include <limits>
#include <vxl_config.h>


namespace vidtk
{


class std_0102_lds
{
};

/// Define traits for a given KLV 0601 tag
/// All tag traits should be defined using the macro below
/// The anonymous enums allow the values available to the
/// compiler to for use in generic programming.  For values
/// that are already enums, a function is provided so the
/// user does not need to worry about enum type clashes.
template <klv_0601_tag tag>
struct klv_0601_traits;
#define KLV_TRAITS(TAG, NAME, T)\
template <> \
struct klv_0601_traits<KLV_0601_##TAG> \
{\
  static inline std::string name() { return NAME; }\
  typedef T type;\
}

//          tag                      string name                        type
//          ---                      -----------                        ----
KLV_TRAITS( CHECKSUM,                "Checksum",                        vxl_uint_16);
KLV_TRAITS( UNIX_TIMESTAMP,          "Unix Time Stamp",                 vxl_uint_64);
KLV_TRAITS( MISSION_ID,              "Mission ID",                      std::string);
KLV_TRAITS( PLATFORM_TAIL_NUMBER,    "Platform Tail Number",            std::string);
KLV_TRAITS( PLATFORM_HEADING_ANGLE,  "Platform Heading Angle",          vxl_uint_16);
KLV_TRAITS( PLATFORM_PITCH_ANGLE,    "Platform Pitch Angle",            vxl_int_16);
KLV_TRAITS( PLATFORM_ROLL_ANGLE,     "Platform Roll Angle",             vxl_int_16);
KLV_TRAITS( PLATFORM_TRUE_AIRSPEED,  "Platform True Airspeed",          vxl_uint_8);
KLV_TRAITS( PLATFORM_IND_AIRSPEED,   "Platform Indicated Airspeed",     vxl_uint_8);
KLV_TRAITS( PLATFORM_DESIGNATION,    "Platform Designation",            std::string);
KLV_TRAITS( IMAGE_SOURCE_SENSOR,     "Image Source Sensor",             std::string);
KLV_TRAITS( IMAGE_COORDINATE_SYSTEM, "Image Coordinate System",         std::string);
KLV_TRAITS( SENSOR_LATITUDE,         "Sensor Latitude",                 vxl_int_32);
KLV_TRAITS( SENSOR_LONGITUDE,        "Sensor Longitude",                vxl_int_32);
KLV_TRAITS( SENSOR_TRUE_ALTITUDE,    "Sensor True Altitude",            vxl_uint_16);
KLV_TRAITS( SENSOR_HORIZONTAL_FOV,   "Sensor Horizontal Field of View", vxl_uint_16);
KLV_TRAITS( SENSOR_VERTICAL_FOV,     "Sensor Vertical Field of View",   vxl_uint_16);
KLV_TRAITS( SENSOR_REL_AZ_ANGLE,     "Sensor Relative Azimuth Angle",   vxl_uint_32);
KLV_TRAITS( SENSOR_REL_EL_ANGLE,     "Sensor Relative Elevation Angle", vxl_int_32);
KLV_TRAITS( SENSOR_REL_ROLL_ANGLE,   "Sensor Relative Roll Angle",      vxl_uint_32);
KLV_TRAITS( SLANT_RANGE,             "Slant Range",                     vxl_uint_32);
KLV_TRAITS( TARGET_WIDTH,            "Target Width",                    vxl_uint_16);
KLV_TRAITS( FRAME_CENTER_LAT,        "Frame Center Latitude",           vxl_int_32);
KLV_TRAITS( FRAME_CENTER_LONG,       "Frame Center Longitude",          vxl_int_32);
KLV_TRAITS( FRAME_CENTER_ELEV,       "Frame Center Elevation",          vxl_uint_16);
KLV_TRAITS( OFFSET_CORNER_LAT_PT_1,  "Offset Corner Latitude Point 1",  vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LONG_PT_1, "Offset Corner Longitude Point 1", vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LAT_PT_2,  "Offset Corner Latitude Point 2",  vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LONG_PT_2, "Offset Corner Longitude Point 2", vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LAT_PT_3,  "Offset Corner Latitude Point 3",  vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LONG_PT_3, "Offset Corner Longitude Point 3", vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LAT_PT_4,  "Offset Corner Latitude Point 4",  vxl_int_16);
KLV_TRAITS( OFFSET_CORNER_LONG_PT_4, "Offset Corner Longitude Point 4", vxl_int_16);
KLV_TRAITS( ICING_DETECTED,          "Icing Detected",                  vxl_uint_8);
KLV_TRAITS( WIND_DIRECTION,          "Wind Direction",                  vxl_uint_16);
KLV_TRAITS( WIND_SPEED,              "Wind Speed",                      vxl_uint_8);
KLV_TRAITS( STATIC_PRESSURE,         "Static Pressure",                 vxl_uint_16);
KLV_TRAITS( DENSITY_ALTITUDE,        "Density Altitude",                vxl_uint_16);
KLV_TRAITS( OUTSIDE_AIR_TEMPERATURE, "Outside Air Temperature",         vxl_int_8);
KLV_TRAITS( TARGET_LOCATION_LAT,     "Target Location Latitude",        vxl_int_32);
KLV_TRAITS( TARGET_LOCATION_LONG,    "Target Location Longitude",       vxl_int_32);
KLV_TRAITS( TARGET_LOCATION_ELEV,    "Target Location Elevation",       vxl_uint_16);
KLV_TRAITS( TARGET_TRK_GATE_WIDTH,   "Target Track Gate Width",         vxl_uint_8);
KLV_TRAITS( TARGET_TRK_GATE_HEIGHT,  "Target Track Gate Height",        vxl_uint_8);
KLV_TRAITS( TARGET_ERROR_EST_CE90,   "Target Error Estimate - CE90",    vxl_uint_16);
KLV_TRAITS( TARGET_ERROR_EST_LE90,   "Target Error Estimate - LE90",    vxl_uint_16);
KLV_TRAITS( GENERIC_FLAG_DATA_01,    "Generic Flag Data 01",            vxl_uint_8);
KLV_TRAITS( SECURITY_LOCAL_MD_SET,   "Security Local Metadata Set",     std_0102_lds);
KLV_TRAITS( DIFFERENTIAL_PRESSURE,   "Differential Pressure",           vxl_uint_16);
KLV_TRAITS( PLATFORM_ANG_OF_ATTACK,  "Platform Angle of Attack",        vxl_int_16);
KLV_TRAITS( PLATFORM_VERTICAL_SPEED, "Platform Vertical Speed",         vxl_int_16);
KLV_TRAITS( PLATFORM_SIDESLIP_ANGLE, "Platform Sideslip Angle",         vxl_int_16);
KLV_TRAITS( AIRFIELD_BAROMET_PRESS,  "Airfield Barometric Pressure",    vxl_uint_16);
KLV_TRAITS( AIRFIELD_ELEVATION,      "Airfield Elevation",              vxl_uint_16);
KLV_TRAITS( RELATIVE_HUMIDITY,       "Relative Humidity",               vxl_uint_8);
KLV_TRAITS( PLATFORM_GROUND_SPEED,   "Platform Ground Speed",           vxl_uint_8);
KLV_TRAITS( GROUND_RANGE,            "Ground Range",                    vxl_uint_32);
KLV_TRAITS( PLATFORM_FUEL_REMAINING, "Platform Fuel Remaining",         vxl_uint_16);
KLV_TRAITS( PLATFORM_CALL_SIGN,      "Platform Call Sign",              std::string);
KLV_TRAITS( WEAPON_LOAD,             "Weapon Load",                     vxl_uint_16);
KLV_TRAITS( WEAPON_FIRED,            "Weapon Fired",                    vxl_uint_8);
KLV_TRAITS( LASER_PRF_CODE,          "Laser PRF Code",                  vxl_uint_16);
KLV_TRAITS( SENSOR_FOV_NAME,         "Sensor Field of View Name",       vxl_uint_8);
KLV_TRAITS( PLATFORM_MAGNET_HEADING, "Platform Magnetic Heading",       vxl_uint_16);
KLV_TRAITS( UAS_LDS_VERSION_NUMBER,  "UAS LDS Version Number",          vxl_uint_8);

#undef KLV_TRAITS


template <klv_0601_tag tag>
struct klv_0601_convert
{
  static const bool has_double = false;
  typedef typename klv_0601_traits<tag>::type type;
  static inline double as_double(const type&)
  {
    return std::numeric_limits<double>::quiet_NaN();
  }
};

#define KLV_CAST(TAG)\
template <> \
struct klv_0601_convert<KLV_0601_##TAG> \
{\
  static const bool has_double = true; \
  typedef klv_0601_traits<KLV_0601_##TAG>::type type; \
  static inline double as_double(const type& val) \
  { \
    return static_cast<double>(val); \
  } \
}

#define KLV_SCALE(TAG, SCALE)\
template <> \
struct klv_0601_convert<KLV_0601_##TAG> \
{\
  static const bool has_double = true; \
  typedef klv_0601_traits<KLV_0601_##TAG>::type type; \
  static inline double as_double(const type& val) \
  { \
    return (static_cast<double>(val) * SCALE) / std::numeric_limits<type>::max(); \
  } \
}

#define KLV_SCALE_OFFSET(TAG, SCALE, OFFSET)\
template <> \
struct klv_0601_convert<KLV_0601_##TAG> \
{\
  static const bool has_double = true; \
  typedef klv_0601_traits<KLV_0601_##TAG>::type type; \
  static inline double as_double(const type& val) \
  { \
    return (static_cast<double>(val) * SCALE) / std::numeric_limits<type>::max() + OFFSET; \
  } \
}

#define KLV_SCALE_INVALID(TAG, SCALE)\
template <> \
struct klv_0601_convert<KLV_0601_##TAG> \
{\
  static const bool has_double = true; \
  typedef klv_0601_traits<KLV_0601_##TAG>::type type; \
  static inline double as_double(const type& val) \
  { \
    return (val == std::numeric_limits<type>::min()) \
           ? std::numeric_limits<double>::quiet_NaN() \
           : (static_cast<double>(val) * SCALE) / std::numeric_limits<type>::max(); \
  } \
}

//                 tag                      scale  offset
//                 ---                      -----  ------
KLV_SCALE(         PLATFORM_HEADING_ANGLE,  360);
KLV_SCALE_INVALID( PLATFORM_PITCH_ANGLE,    20);
KLV_SCALE_INVALID( PLATFORM_ROLL_ANGLE,     50);
KLV_SCALE(         PLATFORM_TRUE_AIRSPEED,  255);
KLV_SCALE(         PLATFORM_IND_AIRSPEED,   255);
KLV_SCALE_INVALID( SENSOR_LATITUDE,         90);
KLV_SCALE_INVALID( SENSOR_LONGITUDE,        180);
KLV_SCALE_OFFSET(  SENSOR_TRUE_ALTITUDE,    19900,  -900);
KLV_SCALE(         SENSOR_HORIZONTAL_FOV,   180);
KLV_SCALE(         SENSOR_VERTICAL_FOV,     180);
KLV_SCALE(         SENSOR_REL_AZ_ANGLE,     360);
KLV_SCALE_INVALID( SENSOR_REL_EL_ANGLE,     180);
KLV_SCALE(         SENSOR_REL_ROLL_ANGLE,   360);
KLV_SCALE(         SLANT_RANGE,             5000000);
KLV_SCALE(         TARGET_WIDTH,            10000);
KLV_SCALE_INVALID( FRAME_CENTER_LAT,        90);
KLV_SCALE_INVALID( FRAME_CENTER_LONG,       180);
KLV_SCALE_OFFSET(  FRAME_CENTER_ELEV,       19900,  -900);
KLV_SCALE_INVALID( OFFSET_CORNER_LAT_PT_1,  0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LONG_PT_1, 0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LAT_PT_2,  0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LONG_PT_2, 0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LAT_PT_3,  0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LONG_PT_3, 0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LAT_PT_4,  0.075);
KLV_SCALE_INVALID( OFFSET_CORNER_LONG_PT_4, 0.075);
KLV_SCALE(         WIND_DIRECTION,          360);
KLV_SCALE(         WIND_SPEED,              100);
KLV_SCALE(         STATIC_PRESSURE,         5000);
KLV_SCALE_OFFSET(  DENSITY_ALTITUDE,        19900,  -900);
KLV_SCALE_INVALID( TARGET_LOCATION_LAT,     90);
KLV_SCALE_INVALID( TARGET_LOCATION_LONG,    180);
KLV_SCALE_OFFSET(  TARGET_LOCATION_ELEV,    19900,  -900);
KLV_CAST(          TARGET_TRK_GATE_WIDTH );
KLV_CAST(          TARGET_TRK_GATE_HEIGHT );
KLV_CAST(          TARGET_ERROR_EST_CE90 );
KLV_CAST(          TARGET_ERROR_EST_LE90 );
KLV_SCALE(         DIFFERENTIAL_PRESSURE,   5000);
KLV_SCALE_INVALID( PLATFORM_ANG_OF_ATTACK,  20);
KLV_SCALE_INVALID( PLATFORM_VERTICAL_SPEED, 180);
KLV_SCALE_INVALID( PLATFORM_SIDESLIP_ANGLE, 20);
KLV_SCALE(         AIRFIELD_BAROMET_PRESS,  5000);
KLV_SCALE_OFFSET(  AIRFIELD_ELEVATION,      19900, -900);
KLV_SCALE(         RELATIVE_HUMIDITY,       100);
KLV_CAST(          PLATFORM_GROUND_SPEED );
KLV_SCALE(         GROUND_RANGE,            5000000);
KLV_SCALE(         PLATFORM_FUEL_REMAINING, 10000);
KLV_SCALE(         PLATFORM_MAGNET_HEADING, 360);
KLV_CAST(          UAS_LDS_VERSION_NUMBER );

#undef KLV_SCALE
#undef KLV_SCALE_OFFSET
#undef KLV_SCALE_INVALID

} // end namespace vidtk


#endif // VIDTK_KLV_0601_TRAITS_H_
