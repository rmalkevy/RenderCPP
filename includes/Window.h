//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_WINDOW_H
#define RENDERCPP_WINDOW_H

#include <iostream>

extern "C" {
#include "../minilibx/mlx.h"
}

class Window final
{
public:
	Window(int width, int height);
	~Window();

	void	prepareWindowAndImage();
	void	clearWindow();
	void	createImage();
	void	putImageToWindow();
	void	keyboardControl();
	void	infinityShowingImage();

	void	*getMlx() const;
	void	*getWin() const;
	void	*getImage() const;
	char	*getLine() const;
	int 	getWidth() const;
	int		getHeight() const;

	void	setMlx( void *mlx );
	void	setWin( void *win );
	void	setImage( void *image );
	void	setLine( char *line );
	void	setWidth(int width);
	void	setHeight(int height);
    char	*line;
private:

	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*image;
};

#endif //RENDERCPP_WINDOW_H
