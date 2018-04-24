# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)  

#set variables
if (UNIX)
set( ENV{CMAKE_SOURCE_DIR} /home/amaresh/code/integration )    
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

# get all *.cpp files recursively
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.hpp ${PROJECT_SOURCE_DIR}/*.h)
message("Files to compile: " ${SRC})
#disable if binary isn't required as output
#add_executable(integrated ${SRC_FILES})

#to make cmake generate a static library
add_library (integrated-static-lib STATIC ${SRC_FILES})
