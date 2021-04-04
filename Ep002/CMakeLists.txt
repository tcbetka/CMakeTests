cmake_minimum_required(VERSION 3.19)

project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "Hello World app"
        LANGUAGES CXX)

# Add our source files here
#add_executable(appBinary source/main.cpp source/Complex.cpp) 
add_executable(appBinary 
        source/main.cpp 
        source/Bitmap.cpp 
        source/Mandlebrot.cpp 
        source/ZoomList.cpp
        source/FractalCreator.cpp
        source/RGB.cpp) 

target_compile_features(appBinary PRIVATE cxx_std_20)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
        message(FATAL_ERROR "In-source builds not allows. Please make a new directory and run from there. You make need to remove CMakeCache.txt")
endif()       