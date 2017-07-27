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

void Light::illuminate(const Vec3d &P, Vec3d &lightDir, Vec3d &lightIntensity, double &distance) const
{
	lightDir = (P - position);
	double r2 = lightDir.dot(lightDir);
	distance = sqrt(r2);
	lightDir *= (1 / distance);
	//lightDir.x /= distance, lightDir.y /= distance, lightDir.z /= distance;
	// avoid division by 0
	lightIntensity = color * (intensity / (4 * M_PI * r2));
}
