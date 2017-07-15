//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_CAMERA_H
#define RENDERCPP_CAMERA_H

#include "Render.h"

class Camera
{
public:
	Camera(Vec3d const &origin);
	~Camera();

	void	findCameraDirection(Vec3d const &pixel);
	void	setCamDir(Vec3d const &dir);
	void	setCamOrig(Vec3d const &orig);
	void	setCamAngle(Vec3d const &angle);
	Vec3d	getCamDir() const;
	Vec3d	getCamOrig() const;
	Vec3d	getCamAngle() const;

private:
	Vec3d	direction;
	Vec3d	origin;
	Vec3d	angle;
};
#endif //RENDERCPP_CAMERA_H
