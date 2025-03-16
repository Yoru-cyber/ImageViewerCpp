cmake_minimum_required(VERSION 3.10)
project(ImageViewerCpp_VERSION_0.0.1)
add_executable(directory directory.cpp)
find_program(CLANG_COMPILER clang++)
if(CLANG_COMPILER)
    message(STATUS "Clang compiler found: ${CLANG_COMPILER}")
    set(CMAKE_CXX_COMPILER ${CLANG_COMPILER})
else()
    message(STATUS "Clang compiler not found, using default compiler.")
endif()

set_target_properties(directory PROPERTIES
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)
