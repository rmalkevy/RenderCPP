cmake_minimum_required(VERSION 3.6)
project(RenderCPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        KeyboardMouseControl.cpp
        Plane.cpp Cylinder.cpp Cone.cpp PhongColor.cpp
        Camera.cpp Light.cpp Render.cpp Sphere.cpp Vec3d.cpp Window.cpp
        includes
        includes/Primitive.h includes/Plane.h includes/RenderFunctions.h
        includes/Cylinder.h includes/Cone.h )
add_executable(RenderCPP ${SOURCE_FILES})