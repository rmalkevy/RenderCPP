//
// Created by Roman Malkevych on 7/13/17.
//

#include "Vec3d.h"

/*
 * Functions for work with vectors
 */

Vec3d& Vec3d::normalize()
{
	double nor2 = length2();
	if (nor2 > 0)
	{
		double invNor = 1 / sqrt(nor2);
		x *= invNor;
		y *= invNor;
		z *= invNor;
	}
	return *this;
}

double Vec3d::length2() const
{
	return (x * x + y * y + z * z);
}

double Vec3d::length() const
{
	return (sqrt(length2()));
}

double Vec3d::dot( Vec3d const &v ) const
{
	return (x * v.x + y * v.y + z * v.z);
}

Vec3d Vec3d::cross( Vec3d const &v ) const
{
	return (Vec3d(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x));
}

double Vec3d::cos( Vec3d const &v ) const
{
	return (this->dot(v) / (this->dot(Vec3d(x, y, z)) * v.dot(v)));
}

/*
 * Implementation of overload operators
 */

Vec3d Vec3d::operator*( const double &f ) const
{
	return (Vec3d(x * f, y * f, z * f));
}

Vec3d Vec3d::operator*( const Vec3d &v ) const
{
	return (Vec3d(x * v.x, y * v.y, z * v.z));
}

Vec3d& Vec3d::operator*=( const Vec3d &v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return (*this);
}

Vec3d Vec3d::operator+( const Vec3d &v ) const
{
	return (Vec3d(x + v.x, y + v.y, z + v.z));
}

Vec3d& Vec3d::operator+=( const Vec3d &v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	return (*this);
}

Vec3d Vec3d::operator-( const Vec3d &v ) const
{
	return (Vec3d(x - v.x, y - v.y, z - v.z));
}
