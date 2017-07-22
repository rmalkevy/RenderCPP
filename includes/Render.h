//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_RENDER_H
#define RENDERCPP_RENDER_H

#include <iostream>
#include <list>
#include "Camera.h"
#include "Window.h"
#include "Primitive.h"

class Render final
{
public:
    Render(Window *window,
           Camera *camera,
           std::list<IPrimitive*>   &listObjects);

    ~Render();
    Window *window;
    Camera *camera;
    std::list< IPrimitive*> *listObjects;
// TODO зробити клас, який зберігатиме проміжні результати роботи інших класів і функцій
};










//class Intersection
//{
//public:
//    Vec3d   intersectionPoint;
//    Vec3d   normal;
//    Vec3d   color;
//    bool    intersect;
//};

#endif //RENDERCPP_RENDER_H
