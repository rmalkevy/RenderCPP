//
// Created by Roman Malkevych on 7/14/17.
//

#include "Window.h"

Window::Window(int width, int height)
{
	// TODO зробити три режими екрану.
	// TODO Там можна буде показати вказівники на функції
	// TODO Зробити перевірку на вхідні ширину і висоту екрану не в конструктрі

	setWidth(width);
	setHeight(height);
	prepareWindowAndImage();
}

Window::~Window()
{
	return ;
}

void Window::prepareWindowAndImage()
{
	setMlx(mlx_init());
	setWin(mlx_new_window(getMlx(), width, height, "RenderCPP"));
	return ;
}

void Window::clearWindow()
{
	mlx_clear_window(getMlx(), getWin());
	return ;
}

void Window::createImage()
{
	int a[3];

	setImage(mlx_new_image(getMlx(), getWidth(), getHeight()));
	setLine(mlx_get_data_addr(getImage(), &a[0], &a[1], &a[2]));
	return ;
}

void Window::putImageToWindow()
{
	mlx_put_image_to_window(getMlx(), getWin(), getImage(), 0, 0);
	return ;
}

void* Window::getMlx() const
{
	return this->mlx;
}

void* Window::getWin() const
{
	return this->win;
}

void* Window::getImage() const
{
	return this->image;
}

char* Window::getLine()
{
	return this->line;
}

int Window::getWidth()
{
	return this->width;
}

int Window::getHeight()
{
	return this->height;
}

void Window::setMlx( void *mlx )
{
	this->mlx = mlx;
}

void Window::setWin( void *win )
{
	this->win = win;
}

void Window::setImage( void *image )
{
	this->image = image;
}

void Window::setLine( char *line )
{
	this->line = line;
}

void Window::setWidth( int width )
{
	if (width >= 120 && width <= 1200)
		this->width = width;
	else
	{
		std::cout << "Width must be in range from 120 to 1200!";
		exit(0);
	}
}

void Window::setHeight( int height )
{
	if (height >= 80 && height <= 800)
		this->height = height;
	else
	{
		std::cout << "Height must be in range from 80 to 800!";
		exit(0);
	}
}