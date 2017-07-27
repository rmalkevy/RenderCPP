//
// Created by Mac on 27.07.17.
//

#include "includes/Cone.h"
#include "includes/RenderFunctions.h"

Cone::Cone(Vec3d position, Vec3d direction, Vec3d color, double angle)
{
    this->position = position;
    this->direction = direction;
    this->color = color;
    this->angle = angle * M_PI / 180 ;
    this->sqCos = cos(this->angle) * cos(this->angle);
    this->sqSin = sin(this->angle) * sin(this->angle);
}

Cone::~Cone()
{
    return ;
}

bool Cone::intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera)
{
    int     first = 0;
    int     second = 1;
    double	dot[2];
    Vec3d	mult[2];
    Vec3d	sub[2];
    Vec3d	delta_p;

    delta_p = rOrigin - position;
    dot[first] = direction.dot(rDir);
    mult[first] = direction * dot[first];
    sub[first] = rDir - mult[first];
    dot[second] = delta_p.dot(direction);
    mult[second] = direction * dot[second];
    sub[second] = delta_p - mult[second];
    double a = sqCos * sub[first].dot(sub[first]);
    a -= sqSin * dot[first] * dot[first];
    double b = 2 * sqCos * sub[first].dot(sub[second]);
    b -= 2 * sqSin * dot[first] * dot[second];
    double c = sqCos * sub[second].dot(sub[second]);
    c -= sqSin * dot[second] * dot[second];

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

Vec3d Cone::findNormal(const Vec3d &intersectionPoint)
{
    Vec3d b = intersectionPoint - position;
    Vec3d a = direction * b.cos(direction);
    Vec3d n = b - a;
    n = n * b * b;
    return n.normalize();
}

Vec3d Cone::getColor()
{
    return this->color;
}