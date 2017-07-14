//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_CAMERA_H
#define RENDERCPP_CAMERA_H

#include "Render.h"

class Camera
{
public:
	Vec3d	findCameraDirection(Vec3d const &pixel);

private:
	Vec3d	camDir;
	Vec3d	camOrig;
	Vec3d	angle;
};
#endif //RENDERCPP_CAMERA_H
