//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_RENDER_H
#define RENDERCPP_RENDER_H

#include <iostream>
#include <list>
#include "Vec3d.h"
#include "Sphere.h"
#include "Primitive.h"
#include "Camera.h"
#include "Window.h"
#include "Light.h"

#include "../minilibx/mlx.h"

void	renderImage(Window &window, Camera &camera, std::list<Sphere> listObjects);
void	renderPixel( Camera &camera, std::list<Sphere> listObjects, Vec3d rayOrig, Vec3d rayDir );

#endif //RENDERCPP_RENDER_H
