//
// Created by Roman Malkevych on 7/13/17.
//

#include "Render.h"
#include "Window.h"


void	renderPixel( double x, double y)
{

}

void	loopScreen(Window &window) // Add list argument
{
	double halfHeight = window.getHeight() / 2;
	double halfWidth = window.getWidth() / 2;

	for (double y = -halfHeight; y < halfHeight; y++)
	{
		for (double x = -halfWidth; x < halfWidth; x++)
		{
			renderPixel(x, y); // Add list argument
		}
	}
}
