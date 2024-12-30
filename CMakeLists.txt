cmake_minimum_required(VERSION 3.22.1)
project(TOH VERSION 1.0)
set (
    SOURCES
    src/main.cpp
    lib/TowerOfHanoi.cpp
)
add_executable(TOH ${SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/include)
