cmake_minimum_required(VERSION 3.14)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source. Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

project("PlayerModel" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

add_library(PlayerModel include/player/player.hpp src/player.cpp)
add_library(jd::PlayerModel ALIAS PlayerModel)

target_include_directories(PlayerModel PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
"$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>") 

set_target_properties(PlayerModel PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)
target_compile_features(PlayerModel PUBLIC cxx_std_17)

find_package(nlohmann_json REQUIRED)

target_link_libraries(PlayerModel PRIVATE nlohmann_json::nlohmann_json)

if(MSVC)
  target_compile_options(PlayerModel PRIVATE /W4 /WX)
else()
  target_compile_options(PlayerModel PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

if (ENABLE_TESTING)
    enable_testing()
    include(CTest)
    add_subdirectory(tests)
endif()
