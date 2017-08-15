cmake_minimum_required(VERSION 3.6)
project(PluginBasedFileFormat)

set(CMAKE_PACKAGE_VERSION "1.0.0 Beta 1")

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(plugins)

set(SOURCE_FILES src/main.cpp include/plugin_base.h src/netflix_catalogue.cpp src/netflix_catalogue.h src/netflix_show.cpp include/netflix_show.h src/dynamic_lib.cpp src/dynamic_lib.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


add_executable(PluginBasedFileFormat ${SOURCE_FILES})
target_link_libraries( PluginBasedFileFormat libdl.so )

## Installation
set(CMAKE_INSTALL_PREFIX install)
install( TARGETS PluginBasedFileFormat DESTINATION bin )

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "PluginShits")
set(CPACK_PACKAGE_VERSION ${CMAKE_PACKAGE_VERSION})
set(CPACK_PACKAGE_CONTACT "Xavier Banks <xavier[dot]xb95[at]gmail.com")
set(CPACK_SET_DESTDIR "${CMAKE_CURRENT_LIST_DIR}/packages")

include(CPack)