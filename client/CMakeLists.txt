# This is personal practises and implementation
# Create by: Amaresh Kumar
# Last modified on April 27th 2018
# 

# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)  

#set variables
if (UNIX)
set( ENV{CMAKE_SOURCE_DIR} /home/amaresh/code/integration/client )    
else() 
set(ENV{CMAKE_SOURCE_DIR} D:/code/integration/client)
endif (UNIX)

project(integrationClient)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#add_executable(integrated ${SRC_FILES})
add_executable(integrationClient integrationClient.cpp)
if (UNIX)
target_link_libraries(integrationClient ${PROJECT_SOURCE_DIR}/../build/bin/libintegrated-static-lib.a)
else()
target_link_libraries(integrationClient ${PROJECT_SOURCE_DIR}/../build/bin/Debug/integrated-static-lib.lib)
endif (UNIX)