//
// Created by Mac on 15.07.17.
//

#include "Camera.h"

Camera::Camera(Vec3d const &origin)
{
	setPosition(origin);
	setDirection(Vec3d(0, 0, 1));
	setAngle(Vec3d(0, 0, 0));
	this->maxDistance = 100000;
	return ;
}

Camera::~Camera()
{
	return ;
}

void Camera::findDirection(Vec3d const &pixel)
{
	Vec3d dir = pixel - getPosition();
	setDirection(dir.normalize());
}

void Camera::setDirection(Vec3d const &dir)
{
	this->direction = dir;
	return ;
}

void Camera::setPosition(Vec3d const &orig)
{
	this->position = orig;
	return ;
}

void Camera::setAngle(Vec3d const &angle)
{
	this->angle = angle;
	return ;
}

void Camera::setMaxDistance(double const &dist)
{
	this->maxDistance = dist;
	return ;
}

Vec3d Camera::getDirection() const
{
	return this->direction;
}

Vec3d Camera::getPosition() const
{
	return  this->position;
}

Vec3d Camera::getAngle() const
{
	return this->angle;
}

double Camera::getMaxDistance() const
{
	return this->maxDistance;
}