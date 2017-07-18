//
// Created by Mac on 16.07.17.
//

#ifndef RENDERCPP_LIGHT_H
#define RENDERCPP_LIGHT_H

#include "Vec3d.h"

class Light
{
public:
    Light();
	Light(const Vec3d &position, const Vec3d &color);
	~Light();

//private:
	Vec3d	position;
	Vec3d	rayDirection;
	Vec3d	rayOrigin;
	Vec3d	color;

};
#endif //RENDERCPP_LIGHT_H