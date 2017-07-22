//
// Created by Roman Malkevych on 7/22/17.
//

#include "includes/Plane.h"

Plane::Plane(Vec3d position, Vec3d direction, Vec3d color)
{
    this->position = position;
    this->direction = direction;
    this->color = color;
    return ;
}

Plane::~Plane()
{
    return ;
}

bool Plane::intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera)
{
    double a = this->direction.dot(rDir);
    double b = this->direction.dot(rOrigin);
    double c = this->position.dot(this->direction);

	double t0 = (fabs(a) > 0.0001) ? (-(b - c) / a) : -1;
    if (t0 > 0)
    {
	    camera.setMaxDistance(t0);
	    return (true);
    }
	return (false);
}

Vec3d Plane::findNormal(const Vec3d & intersectionPoint)
{
	Vec3d a;
	a = intersectionPoint;
	return this->direction;
}

Vec3d Plane::getColor()
{
	return this->color;
}

double Plane::getIntersectDistance()
{
	return this->t;
}