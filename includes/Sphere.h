//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_SPHERE_H
#define RENDERCPP_SPHERE_H

#include <iostream>
#include <vector>
#include "Vec3d.h"
#include "Camera.h"

class Sphere
{
public:
	Sphere(Vec3d position, Vec3d color, double radius);
	~Sphere();
	bool	intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera);
	Vec3d	findNormal(const Vec3d & intersectionPoint);
	double	getIntersectDistance();
	Vec3d	getColor();


private:
	Vec3d pos;
	Vec3d color;
	double radius;
	double sqRadius;
	double t;
};
#endif