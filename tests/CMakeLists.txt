####################################################################################################
# Find packages and libraries
####################################################################################################
find_package (Threads REQUIRED)
find_package (GTest REQUIRED)

find_library (gmock google-mock)

message (STATUS "-------> ${gmock}")
message (STATUS "-------> ${CMAKE_LIBRARY_PATH}")

include_directories(${INCLUDE_SRC_DIR})

####################################################################################################
# Build
####################################################################################################
add_executable (test
    agent.cc
    ${SOURCE_SRC_DIR}/agent.c
)

target_link_libraries (test
    ${GTEST_BOTH_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    gmock
)
