//
// Created by Mac on 15.07.17.
//

#include "Camera.h"

Camera::Camera(Vec3d const &origin)
{
	setCamOrig(origin);
	setCamDir(Vec3d(0, 0, 1));
	setCamAngle(Vec3d(0, 0, 0));
	return ;
}

Camera::~Camera()
{
	return ;
}

void Camera::findCameraDirection(Vec3d const &pixel)
{
	Vec3d dir = pixel - getCamOrig();
	setCamDir(dir.normalize());
}

void Camera::setCamDir(Vec3d const &dir)
{
	this->direction = dir;
	return ;
}

void Camera::setCamOrig(Vec3d const &orig)
{
	this->origin = orig;
	return ;
}

void Camera::setCamAngle(Vec3d const &angle)
{
	this->angle = angle;
	return ;
}

Vec3d Camera::getCamDir() const
{
	return this->direction;
}

Vec3d Camera::getCamOrig() const
{
	return  this->origin;
}

Vec3d Camera::getCamAngle() const
{
	return this->angle;
}