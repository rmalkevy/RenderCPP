//
// Created by Roman Malkevych on 7/13/17.
//

#include "Render.h"
#include "Window.h"
#include "Camera.h"


Vec3d	renderPixel( Vec3d pixel)
{

}

void	tracingScreen(Window &window, Camera &camera) // Add list argument
{
	double halfHeight = window.getHeight() / 2;
	double halfWidth = window.getWidth() / 2;

	for (double y = -halfHeight; y < halfHeight; y++)
	{
		for (double x = -halfWidth; x < halfWidth; x++)
		{
			Vec3d color = renderPixel(Vec3d(x, y, 0)); // Add list argument
		}
	}
}

void	renderImage(Window &window, Camera &camera)
{
	window.clearWindow();
	window.createImage();

	tracingScreen(window, camera);

	window.putImageToWindow();
	//window.keyboardControl(); // TODO написати функцію з обробки клавіш
	window.infinityShowingImage();
}