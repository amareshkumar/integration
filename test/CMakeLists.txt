# This is personal practises and implementation
# Create by: Amaresh Kumar
# Last modified on April 27th 2019

cmake_minimum_required(VERSION 3.2)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)  

# enable address sanitizer
add_compile_options(-fsanitize=address)

project(test_integrated)

################################
# GTest
################################
enable_testing()

#set variables
if (UNIX)
set( ENV{gtest_SOURCE_DIR} /home/amaresh/code/integration )    #needs to be changed 
else() 
set(ENV{gtest_SOURCE_DIR} C:/code/integration/test/)
endif (UNIX)
include_directories(${gtest_SOURCE_DIR}/build/googletest-src/googletest/include ${gtest_SOURCE_DIR})

##flags to 

add_compile_options(/MD) 
add_compile_options(/MDd) 

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

#include directory
include_directories (${CMAKE_CURRENT_BINARY_DIR}/googletest-src/googletest/include)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(test_integrated main_test.cpp )
target_compile_options (test_integrated PRIVATE -std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS  "/FORCE")
# Link test executable against gtest & gtest_main
target_link_libraries(test_integrated gtest gtest_main)
#add_test( test_integrated main_test)

message ("Source files to be compiled: " ${test_integrated})


#add details as main CMakeList need a library named "test"
#add_library(test STATIC main_test.cpp)
#target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#[===[

#link integrated-static-lib library
if (UNIX)
target_link_libraries(test_integrated ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/libintegrated-static-lib.a)
else()
target_link_libraries(test_integrated ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/Debug/integrated-static-lib.lib)
endif (UNIX)

#add details as main CMakeList need a library named "test"
#add_library(test STATIC main_test.cpp)
#target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#link integrated-static-lib library
if (UNIX)
target_link_libraries(test_integrated ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/libintegrated-static-lib.a)
else()
target_link_libraries(test_integrated ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/Debug/integrated-static-lib.lib)
endif (UNIX)
#]===]