//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_VEC3_H
#define RENDERCPP_VEC3_H

#include <iostream>
#include <cmath>

class Vec3d final
{
public:
	double x, y, z;

	Vec3d() : x(0) , y(0), z(0) {}
	Vec3d(double xx) : x(xx), y(xx), z(xx) {}
	Vec3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}

	Vec3d&	normalize();
	double	dot(Vec3d const &v) const;
	Vec3d	cross(Vec3d const &v) const;
	double	length() const;
	double	length2() const;
	double	cos(Vec3d const &v) const;
//	Vec3d	rotationVector(Vec3d &v);
//	Vec3d	translateVector(Vec3d &v);

	Vec3d operator * (const double &f) const;
	Vec3d operator * (const Vec3d &v) const;
	Vec3d operator + (const Vec3d &v) const;
	Vec3d operator - (const Vec3d &v) const;
	Vec3d&operator += (const Vec3d &v);
	Vec3d&operator *= (const Vec3d &v);
};

#endif
