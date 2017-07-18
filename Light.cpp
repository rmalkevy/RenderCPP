//
// Created by Mac on 16.07.17.
//

#include "includes/Light.h"

Light::Light() {
    this->position = Vec3d(0, 0, -1000);
    this->color = Vec3d(255, 255, 255);
}

Light::Light(const Vec3d &position, const Vec3d &color)
{
	this->position = position;
	this->color = color;
	return ;
}

Light::~Light()
{
	return ;
}