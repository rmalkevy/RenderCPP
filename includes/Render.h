//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_RENDER_H
#define RENDERCPP_RENDER_H

#include <iostream>
#include <list>
#include "Vec3d.h"
#include "Sphere.h"
#include "Camera.h"
#include "Window.h"
#include "Light.h"
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

Render::Render(Window *window, Camera *camera, std::list<IPrimitive *>  &listObjects)
{
    this->window = window;
    this->camera = camera;
    this->listObjects = &listObjects;
}

Render::~Render()
{
    return ;
}









class Intersection
{
public:
    Vec3d   intersectionPoint;
    Vec3d   normal;
    Vec3d   color;
    bool    intersect;
};
void	renderImage(Render &render);
void	renderPixel(Camera &camera,
                    std::list< IPrimitive*> &listObjects,
                    Vec3d rayOrig,
                    Vec3d rayDir);
void	tracingScreen(Window &window,
                      Camera &camera,
                      std::list< IPrimitive*> &listObjects );

#endif //RENDERCPP_RENDER_H
