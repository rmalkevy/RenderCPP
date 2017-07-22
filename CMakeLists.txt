cmake_minimum_required(VERSION 3.6)
project(RenderCPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp includes Camera.cpp Light.cpp Render.cpp Sphere.cpp Vec3d.cpp Window.cpp includes/Primitive.h includes/Plane.h Plane.cpp includes/RenderFunctions.h)
add_executable(RenderCPP ${SOURCE_FILES})