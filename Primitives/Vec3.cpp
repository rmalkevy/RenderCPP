//
// Created by Roman Malkevych on 7/13/17.
//

#include "Vec3.h"

/*
 * Functions for work with vectors
 */

Vec3& Vec3::normalize()
{
	T nor2 = length2();
	if (nor2 > 0)
	{
		T invNor = 1 / sqrt(nor2);
		x *= invNor;
		y *= invNor;
		z *= invNor;
	}
	return *this;
}

T Vec3::length2() const
{
	return (x * x + y * y + z * z);
}

T Vec3::length() const
{
	return (sqrt(length2()));
}

T Vec3::dot( Vec3<T> const &v ) const
{
	return (x * v.x + y * v.y + z * v.z);
}

Vec3 Vec3::cross( Vec3<T> const &v ) const
{
	return (Vec3<T>(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x));
}



/*
 * Implementation of overload operators
 */

Vec3<T> Vec3::operator*( const T &f ) const
{
	return (Vec3<T>(x * f, y * f, z * f));
}

Vec3<T> Vec3::operator*( const Vec3<T> &v ) const
{
	return (Vec3<T>(x * v.x, y * v.y, z * v.z));
}

Vec3<T>& Vec3::operator*=( const Vec3<T> &v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return (*this);
}

Vec3<T> Vec3::operator+( const Vec3<T> &v ) const
{
	return (Vec3<T>(x + v.x, y + v.y, z + v.z));
}

Vec3<T>& Vec3::operator+=( const Vec3<T> &v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	return (*this);
}

Vec3<T> Vec3::operator-( const Vec3<T> &v ) const
{
	return (Vec3<T>(x - v.x, y - v.y, z - v.z));
}
