//
// Created by Roman Malkevych on 7/18/17.
//

#ifndef RENDERCPP_PRIMITIVE_H
#define RENDERCPP_PRIMITIVE_H

#include "Vec3d.h"
#include "Camera.h"

class IPrimitive
{
public:
    IPrimitive() {}
    virtual ~IPrimitive() {}
    virtual bool	intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera) = 0;
    virtual Vec3d	findNormal(const Vec3d & intersectionPoint) = 0;
    virtual Vec3d	getColor() = 0;

    // TODO Можливо варто додати getters and setters?
};
#endif //RENDERCPP_PRIMITIVE_H
