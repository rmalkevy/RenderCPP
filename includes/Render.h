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

class Render
{
// TODO зробити клас, який зберігатиме проміжні результати роботи інших класів і функцій
};

void	renderImage(Window &window, Camera &camera, std::vector< IPrimitive*> &listObjects);
void	renderPixel( Camera &camera, std::vector< IPrimitive*> &listObjects, Vec3d rayOrig, Vec3d rayDir );

#endif //RENDERCPP_RENDER_H
