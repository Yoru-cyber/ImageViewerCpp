cmake_minimum_required(VERSION 3.10)

project(ImageViewerCpp_VERSION_0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CXXFLAGS  "-Werror -Wextra -Wpedantic -Wmissing-include-dirs -Wall -std=c++17")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")
find_program(CLANG_COMPILER clang++)

if(CLANG_COMPILER)
    message(STATUS "Clang compiler found: ${CLANG_COMPILER}")
    set(CMAKE_CXX_COMPILER ${CLANG_COMPILER})
else()
    message(STATUS "Clang compiler not found, using default compiler.")
endif()

add_executable(directory directory.cpp)

set_target_properties(directory PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

target_link_libraries(directory PRIVATE Qt6::Widgets)
