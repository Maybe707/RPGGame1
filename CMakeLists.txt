cmake_minimum_required(VERSION 3.0.0)
project(RPGGame VERSION 0.1.0)

file(GLOB SOURCES src/*.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(RPGGame ${SOURCES})

include_directories(src)
include_directories(lib/SFML-2.5.1-sources/SFML-2.5.1/include)
add_subdirectory(lib/SFML-2.5.1-sources/SFML-2.5.1)
target_link_libraries(RPGGame sfml-graphics)

include some library
