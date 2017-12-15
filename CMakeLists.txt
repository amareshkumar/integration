# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

#set variables
#$CMAKE_SOURCE_DIR:= 
set( ENV{CMAKE_SOURCE_DIR} D:/code/integration)
# Project's name

project(integrated)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/inc")

add_executable(integrated ${PROJECT_SOURCE_DIR}/source/main.cpp)
