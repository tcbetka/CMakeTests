cmake_minimum_required(VERSION 3.19)

project(ParticleFire
        VERSION 0.0.1
        DESCRIPTION "Particle Fire Explosion"
        LANGUAGES CXX)

# Add our source files here
add_executable(particles source/main.cpp) 

include_directories(/usr/include/SDL2)
link_directories(/usr/lib/x86_64-linux-gnu/)

add_library(SDL2 STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)

target_compile_features(particles PRIVATE cxx_std_20)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
        message(FATAL_ERROR "In-source builds not allows. Please make a new directory and run from there. You make need to remove CMakeCache.txt")
endif()       