//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_SPHERE_H
#define RENDERCPP_SPHERE_H

#include <iostream>
#include <vector>
#include "Vec3d.h"
#include "Camera.h"
#include "Primitive.h"

class Sphere : public IPrimitive
{
public:
	Sphere(Vec3d position, Vec3d color, double radius); // TODO додати аргумент direction
	~Sphere();
	bool	intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera) override ;
	Vec3d	findNormal(const Vec3d & intersectionPoint) override ;
	double	getIntersectDistance() ;
	Vec3d	getColor() override ;


private:
	Vec3d pos;
    Vec3d direction;
	Vec3d color;
	double radius; // TODO зробити за допомогою цієї змінної пульсуючу кулю
	double sqRadius;
	double t;
};
#endif
