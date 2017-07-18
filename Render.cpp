//
// Created by Roman Malkevych on 7/13/17.
//

#include "includes/Render.h"

void    putColorToPixel(Window &window, const Vec3d &color, const double &x, const double &y)
{
    int			pixel;

    pixel = (int)(((x + window.getWidth() / 2) + (y + window.getHeight() / 2) * window.getWidth()) * 4);
    window.line[pixel + 0] = (unsigned char)(color.z * 255);
    window.line[pixel + 1] = (unsigned char)(color.y * 255);
    window.line[pixel + 2] = (unsigned char)(color.x * 255);
}

Vec3d	makePixelColor(const Camera &camera, const double &intensity)
{
    double lambert = camera.light.rayDirection.dot(camera.normal);
    double red = (0.8 - camera.color.x) * pow(lambert, 15) * 0.9 * intensity;
    double green = (0.8 - camera.color.y) * pow(lambert, 15) * 0.9 * intensity;
    double blue = (0.8 - camera.color.z) * pow(lambert, 15) * 0.9 * intensity;
    return Vec3d(red, green, blue);
}

Vec3d	tracingLight( Camera &camera, std::list<Sphere> listObjects )
{
	Vec3d distance = camera.light.position - camera.intersectionPoint;
	camera.setMaxDistance(distance.length());
	if ( distance.dot(camera.normal) <= 0 )
	{
		return Vec3d(0);
	}

	camera.light.rayOrigin = camera.intersectionPoint;
	camera.light.rayDirection = distance.normalize();
	renderPixel(camera, listObjects, camera.light.rayOrigin, camera.light.rayDirection);
	if (!camera.intersect)
	{
		return makePixelColor(camera, 1);
	}
	else
	{
		return makePixelColor(camera, 0.1);
	}
}

void	renderPixel( Camera &camera, std::list<Sphere> listObjects, Vec3d rayOrig, Vec3d rayDir )
{
	for ( std::list<Sphere>::iterator it = listObjects.begin(); it != listObjects.end(); it++ )
	{
		if ( it->intersection(rayOrig, rayDir, camera) )
		{
			camera.intersectionPoint = camera.getDirection() * camera.getMaxDistance();
			camera.intersectionPoint += camera.getPosition();
			camera.normal = it->findNormal(camera.intersectionPoint);
			camera.color = it->getColor();
			camera.intersect = true;
		}
	}

}

void	tracingScreen( Window &window, Camera &camera, std::list<Sphere> listObjects )
{
	double halfHeight = window.getHeight() / 2;
	double halfWidth = window.getWidth() / 2;

	for (double y = -halfHeight; y < halfHeight; y++)
	{
		for (double x = -halfWidth; x < halfWidth; x++)
		{
			// TODO потім дописати поворот pixel
			camera.intersect = false;
			camera.findDirection(Vec3d(x, y, 0));
			camera.setMaxDistance(100000);
			renderPixel(camera, listObjects, camera.getPosition(), camera.getDirection());
			if (camera.intersect)
			{
				putColorToPixel(window, tracingLight(camera, listObjects), x, y);
			}
		}
	}
}

void	renderImage( Window &window, Camera &camera, std::list<Sphere> listObjects )
{
    window.clearWindow();
	window.createImage();


	tracingScreen(window, camera, listObjects);

	window.putImageToWindow();
	//window.keyboardControl(); // TODO написати функцію з обробки клавіш
	window.infinityShowingImage();
}