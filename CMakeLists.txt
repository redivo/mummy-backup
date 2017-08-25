cmake_minimum_required(VERSION 2.6)
project (mummy-backup)

# Use the pkg-config module for CMake
include(FindPkgConfig)

set(INCLUDE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

####################################################################################################
# Subdirectories
####################################################################################################
add_subdirectory(${SOURCE_SRC_DIR})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
