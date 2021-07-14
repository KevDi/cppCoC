cmake_minimum_required(VERSION 3.14)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source. Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

project("cppCoC" VERSION 1.0.0 LANGUAGES CXX)

option(ENABLE_TESTING "Build with Tests." ON)

add_subdirectory(models)