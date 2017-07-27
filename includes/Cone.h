//
// Created by Mac on 27.07.17.
//

#ifndef RENDERCPP_CONE_H
#define RENDERCPP_CONE_H

#include "Primitive.h"

class Cone : public IPrimitive
{
public:
    Cone(Vec3d position, Vec3d direction, Vec3d color, double angle);
    ~Cone();
    bool	intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera) override ;
    Vec3d	findNormal(const Vec3d & intersectionPoint) override ;
    Vec3d	getColor() override ;

private:
    Vec3d position;
    Vec3d direction;
    Vec3d color;
    double angle;
    double sqCos;
    double sqSin;
};
#endif //RENDERCPP_CONE_H
