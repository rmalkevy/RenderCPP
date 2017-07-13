//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_VEC3_H
#define RENDERCPP_VEC3_H

#include <iostream>
#include <cmath>

template <typename T>

class Vec3
{
public:
	T x, y, z;

	Vec3() : x(T(0)) , y(T(0)), z(T(0)) {}
	Vec3(T xx) : x(xx), y(xx), z(xx) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	Vec3& normalize();
	T dot(Vec3<T> const &v) const;
	Vec3<T> cross(Vec3<T> const &v) const;
	T length() const;
	T length2() const;

	Vec3<T>	operator * (const T &f) const;
	Vec3<T> operator * (const Vec3<T> &v) const;
	Vec3<T> operator + (const Vec3<T> &v) const;
	Vec3<T> operator - (const Vec3<T> &v) const;
	Vec3<T>&operator += (const Vec3<T> &v);
	Vec3<T>&operator *= (const Vec3<T> &v);
};

typedef Vec3<double> Vec3d;

#endif
