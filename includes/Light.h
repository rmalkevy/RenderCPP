//
// Created by Mac on 16.07.17.
//

#ifndef RENDERCPP_LIGHT_H
#define RENDERCPP_LIGHT_H

#include "Vec3d.h"

class Light final
{
public:
    Light();
	Light(const Vec3d &position, const Vec3d &color);
	~Light();
	void illuminate(const Vec3d &P, Vec3d &lightDir, Vec3d &lightIntensity, double &distance) const;

//private:
	Vec3d	position;
	Vec3d	rayDirection;
	Vec3d	rayOrigin;
	Vec3d	color;
	double	intensity;

};
#endif //RENDERCPP_LIGHT_H
