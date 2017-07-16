//
// Created by Mac on 16.07.17.
//

#include "Light.h"

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