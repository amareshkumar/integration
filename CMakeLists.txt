# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)  

#set variables
if (UNIX)
set( ENV{CMAKE_SOURCE_DIR} /home/code/integration )    #needs to be changed 
else() 
set(ENV{CMAKE_SOURCE_DIR} D:/code/integration)
endif (UNIX)

project(integrated)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/inc")
include_directories("${PROJECT_SOURCE_DIR}/../../external/pthreads")

source_group("include"        FILES ${PROJECT_SOURCE_DIR}/inc)

# get all *.cpp files recursively
#file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.hpp ${PROJECT_SOURCE_DIR}/*.h)
#list(REMOVE_ITEM SRC_FILES "test/main_test.cpp")

file (GLOB lib_src include/*.hpp include/*.h source/*.cpp)

message("Files to compile: " ${SRC_FILES})

#to make cmake generate a static library

#add_library (integrated-static-lib STATIC ${SRC_FILES})
add_library (integrated-static-lib STATIC ${lib_src})

add_custom_target (test_integrated)
add_dependencies  (test_integrated main_test)
