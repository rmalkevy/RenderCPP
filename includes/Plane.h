//
// Created by Roman Malkevych on 7/22/17.
//

#ifndef RENDERCPP_PLANE_H
#define RENDERCPP_PLANE_H

#include "Vec3d.h"
#include "Camera.h"
#include "Primitive.h"

class Plane : public IPrimitive
{
public:
    Plane(Vec3d position, Vec3d direction, Vec3d color); // TODO додати аргумент direction
    ~Plane();
    bool	intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera) override ;
	Vec3d	findNormal(const Vec3d & intersectionPoint) override ;
    double	getIntersectDistance() ;
    Vec3d	getColor() override ;


private:
    Vec3d position;
    Vec3d direction;
    Vec3d color;
    double t;
};

#endif //RENDERCPP_PLANE_H
