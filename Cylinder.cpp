//
// Created by Mac on 27.07.17.
//

#include "includes/Cylinder.h"
#include "includes/RenderFunctions.h"

Cylinder::Cylinder(Vec3d position, Vec3d direction, Vec3d color, double radius)
{
    this->position = position;
    this->direction = direction;
    this->color = color;
    this->sqRadius = radius * radius;
    return ;
}

Cylinder::~Cylinder()
{
    return ;
}

bool Cylinder::intersection(const Vec3d &rOrigin, const Vec3d &rDir, Camera &camera)
{
    double	dot;
    Vec3d	mult;
    Vec3d	sub1;
    Vec3d	sub2;
    Vec3d	delta_p;

    dot = this->direction.dot(rDir);
    mult = this->direction * dot;
    sub1 = rDir - mult;

    // TODO тут можна скоротити розрахунки за рахунок попереднього підрахування sub2
    delta_p = rOrigin - this->position;
    dot = this->direction.dot(delta_p);
    mult = this->direction * dot;
    sub2 = delta_p - mult;

    double a = sub1.dot(sub1);
    double b = 2 * sub1.dot(sub2);
    double c = sub2.dot(sub2) - sqRadius;

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

Vec3d Cylinder::findNormal(const Vec3d &intersectionPoint)
{
    Vec3d b = intersectionPoint - this->position;
    Vec3d a = this->direction * b.dot(this->direction);
    Vec3d rv = b - a;
    return rv.normalize();
}

Vec3d Cylinder::getColor()
{
    return this->color;
}