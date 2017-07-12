cmake_minimum_required(VERSION 3.6)
project(RenderCPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Primitives/Sphere.h Primitives/Sphere.cpp Primitives/Primitive.h Primitives/Vector3f.h)
add_executable(RenderCPP ${SOURCE_FILES})