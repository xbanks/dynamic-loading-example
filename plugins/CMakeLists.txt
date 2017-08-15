cmake_minimum_required(VERSION 3.6)
project(Plugins)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES json_plugin.cpp json_plugin.h)

include_directories( ../include )

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_library(json SHARED ${SOURCES})

install( TARGETS json DESTINATION lib )