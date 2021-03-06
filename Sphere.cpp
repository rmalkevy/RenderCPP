//
// Created by Mac on 12.07.17.
//

#include "includes/Sphere.h"
#include "includes/RenderFunctions.h"

Sphere::Sphere( Vec3d position, Vec3d color, double radius )
{
	this->pos = position;
	this->color = color;
	this->radius = radius;
	this->sqRadius = radius * radius;
	t = 100000;
	return ;
}

Sphere::~Sphere()
{
	return ;
}

bool Sphere::intersection( const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera )
{
	Vec3d len = rOrigin - pos;

	double a = rDir.dot(rDir);
	double b = 2 * rDir.dot(len);
	double c = len.dot(len) - sqRadius;

	double discr = b * b - 4 * a * c;
	if (discr < 0)
		return (false);

	double sqrtDiscr = sqrt(discr);
	double t0 = (-b + sqrtDiscr) / 2;
	double t1 = (-b - sqrtDiscr) / 2;

	t0 = minDistance(t0, t1);
	if (t0 < camera.getMaxDistance() && t0 > 0.00001)
	{
		camera.setMaxDistance(t0);
		return (true);
	}
	return (false);
}

Vec3d Sphere::findNormal( const Vec3d &intersectionPoint )
{
	Vec3d normal = intersectionPoint - this->pos;
	return ( normal.normalize() );
}

double Sphere::getIntersectDistance()
{
	return this->t;
}

Vec3d Sphere::getColor()
{
	return this->color;
}