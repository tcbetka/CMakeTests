cmake_minimum_required(VERSION 3.19)

project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "Hello World app"
        LANGUAGES CXX)

add_executable(HelloAppBinary source/main.cpp)

target_compile_features(HelloAppBinary PRIVATE cxx_std_20)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
        message(FATAL_ERROR "In-source builds not allows. Please make a new directory and run from there. You make need to remove CMakeCache.txt")
endif()       