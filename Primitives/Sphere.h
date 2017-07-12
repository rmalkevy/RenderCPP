//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_SPHERE_H
#define RENDERCPP_SPHERE_H

#include <iostream>
#include <vector>

class Sphere
{
private:
	std::vector<float> position;
	std::vector<float> color;
	float radius;
	float sqRadius;

public:
	Sphere(std::vector<float> position, std::vector<float> color, float radius);
	~Sphere();
	bool intersection();

};
#endif
