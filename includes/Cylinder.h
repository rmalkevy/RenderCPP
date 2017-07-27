//
// Created by Mac on 24.07.17.
//

#ifndef RENDERCPP_CYLINDER_H
#define RENDERCPP_CYLINDER_H

#include "Primitive.h"

class Cylinder : public IPrimitive
{
public:
    Cylinder(Vec3d position, Vec3d direction, Vec3d color, double radius);
    ~Cylinder();
    bool	intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera) override ;
    Vec3d	findNormal(const Vec3d & intersectionPoint) override ;
    Vec3d	getColor() override ;

private:
    Vec3d position;
    Vec3d direction;
    Vec3d color;
    double radius;
    double sqRadius;
};

#endif //RENDERCPP_CYLINDER_H
