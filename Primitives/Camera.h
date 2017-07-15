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

	void	findDirection(Vec3d const &pixel);
	void	setDirection(Vec3d const &dir);
	void	setOrigin(Vec3d const &orig);
	void	setAngle(Vec3d const &angle);
	void	setMaxDistance(double const &dist);
	Vec3d	getDirection() const;
	Vec3d	getOrigin() const;
	Vec3d	getAngle() const;
	double	getMaxDistance() const;

private:
	Vec3d	direction;
	Vec3d	origin;
	Vec3d	angle;
	double	maxDistance;
};
#endif //RENDERCPP_CAMERA_H
