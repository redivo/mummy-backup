cmake_minimum_required(VERSION 2.6)
project (mummy-backup)

# Use the pkg-config module for CMake
include(FindPkgConfig)

set(INCLUDE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

####################################################################################################
# Subdirectories
####################################################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
