find_package(GeographicLib REQUIRED)
include_directories(SYSTEM ${GeographicLib_INCLUDE_DIR})

add_library( vidtk_geographic
  geo_coords.h  geo_coords.cxx
)
target_link_libraries(vidtk_geographic ${GeographicLib_LIBRARY})
install(TARGETS vidtk_geographic EXPORT vidtk
  RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib
)
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include
  FILES_MATCHING PATTERN "*.h"
)
export( TARGETS vidtk_geographic APPEND FILE "${VIDTK_EXPORT_FILE}")

if( VIDTK_ACTIVITY_SDK_INSTALL )
   install( TARGETS vidtk_geographic
     EXPORT activity-sdk-targets DESTINATION activity_sdk/lib )
endif()

if( VIDTK_EVENT_SDK_INSTALL)
   install( TARGETS vidtk_geographic
     EXPORT event-sdk-targets DESTINATION event_sdk/lib )
endif()

if( VIDTK_COMMON_SDK_INSTALL )
   install( TARGETS vidtk_geographic
     EXPORT common-sdk-targets DESTINATION common_sdk/lib )
endif( VIDTK_COMMON_SDK_INSTALL )

if( VIDTK_BUILD_TESTS )
  add_subdirectory( tests )
endif()
