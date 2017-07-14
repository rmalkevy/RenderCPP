//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_WINDOW_H
#define RENDERCPP_WINDOW_H

#include "Render.h"

class Window
{
public:
	Window(int width, int height);
	~Window();

	void	prepareWindowAndImage();
	void	clearWindow();
	void	createImage();
	void	putImageToWindow();

	void	*getMlx() const;
	void	*getWin() const;
	void	*getImage() const;
	char	*getLine();
	int 	getWidth();
	int		getHeight();

	void	setMlx( void *mlx );
	void	setWin( void *win );
	void	setImage( void *image );
	void	setLine( char *line );
	void	setWidth(int width);
	void	setHeight(int height);

private:
	void	*mlx;
	void	*win;
	void	*image;
	char	*line;
	int		width;
	int		height;
};

#endif //RENDERCPP_WINDOW_H
