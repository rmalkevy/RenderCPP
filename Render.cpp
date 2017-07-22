//
// Created by Roman Malkevych on 7/13/17.
//

#include "includes/Render.h"

Render::Render(Window *window, Camera *camera, std::list<IPrimitive *>  &listObjects)
{
	this->window = window;
	this->camera = camera;
	this->listObjects = &listObjects;
}

Render::~Render()
{
	return ;
}
//
//void    putColorToPixel(Window &window, const Vec3d &color, const double &x, const double &y)
//{
//    int			pixel;
//
//    pixel = (int)(((x + window.getWidth() / 2) + (y + window.getHeight() / 2) * window.getWidth()) * 4);
//    window.line[pixel + 0] = (unsigned char)(color.z * 255);
//    window.line[pixel + 1] = (unsigned char)(color.y * 255);
//    window.line[pixel + 2] = (unsigned char)(color.x * 255);
//}
//
//Vec3d	makePixelColor(const Camera &camera, const double &intensity)
//{
////    std::cout << "x = " << camera.normal.x << " y = " << camera.normal.y << " z = " << camera.normal.x << std::endl;
//    double lambert = camera.light.rayDirection.dot(camera.normal);
//    double red = camera.color.x * lambert * intensity;
//    double green = camera.color.y * lambert * intensity;
//    double blue =  camera.color.z * lambert * intensity;
//    return Vec3d(red, green, blue);
//}
//
//Vec3d	tracingLight( Camera &camera, std::list< IPrimitive*> listObjects )
//{
//	Vec3d distance = camera.light.position - camera.intersectionPoint;
//	camera.setMaxDistance(distance.length());
//	if ( distance.dot(camera.normal) <= 0 )
//	{
//		return Vec3d(0);
//	}
//
//	camera.light.rayOrigin = camera.intersectionPoint;
//	camera.light.rayDirection = distance.normalize();
//	renderPixel(camera, listObjects, camera.light.rayOrigin, camera.light.rayDirection);
////	if (camera.intersect)
////	{
//		return makePixelColor(camera, 1);
////	}
////	else
////	{
////		return makePixelColor(camera, 0.1);
////	}
//}
//
//void	renderPixel( Camera &camera, std::list<IPrimitive*> &listObjects, Vec3d rayOrig, Vec3d rayDir )
//{
//	//for ( std::list<IPrimitive *>::iterator it = listObjects.begin(); it != listObjects.end(); it++ )
//	for (auto it : listObjects)
//    {
//		if ( (*it).intersection(rayOrig, rayDir, camera) )
//		{
//			camera.intersectionPoint = camera.getDirection() * camera.getMaxDistance();
//			camera.intersectionPoint += camera.getPosition();
//			camera.normal = (*it).findNormal(camera.intersectionPoint);
//			camera.color = (*it).getColor();
//			camera.intersect = true;
//		}
//	}
//
//}
//
//void	tracingScreen( Window &window, Camera &camera, std::list< IPrimitive*> &listObjects )
//{
//	double halfHeight = window.getHeight() / 2;
//	double halfWidth = window.getWidth() / 2;
//
//	for (double y = -halfHeight; y < halfHeight; y++)
//	{
//		for (double x = -halfWidth; x < halfWidth; x++)
//		{
//			// TODO потім дописати поворот pixel
//			camera.intersect = false;
//			camera.findDirection(Vec3d(x, y, 0));
//			camera.setMaxDistance(100000);
//			renderPixel(camera, listObjects, camera.getPosition(), camera.getDirection());
//			if (camera.intersect)
//			{
//				putColorToPixel(window, tracingLight(camera, listObjects), x, y);
//			}
//		}
//	}
//}
//
//int		my_key_funct(int keycode, void *mod)
//{
//    Render *render = (Render*)mod;
//    mlx_destroy_image(render->window->getMlx(), render->window->getImage());
//    if (keycode == 53)
//    {
//        mlx_destroy_window(render->window->getMlx(), render->window->getWin());
//        exit(0);
//    }
////    addition_funct(keycode, mod);
//    tracingScreen(*render->window, *render->camera, *render->listObjects);
//    return (0);
//}
//
//
//void keyboardControl(Render &render)
//{
//    //TODO зробити клас, який буде включати в себе Window, Camera, List
//
//    mlx_hook(render.window->getWin(), 2, 5, (int (*)())my_key_funct, (void*)(&render));
//    return ;
//}
//
//void	renderImage( Render &render )
//{
//    render.window->clearWindow();
//    render.window->createImage();
//
//	tracingScreen(*render.window, *render.camera, *render.listObjects);
//
//    render.window->putImageToWindow();
//	keyboardControl(render); // TODO написати функцію з обробки клавіш
//    render.window->infinityShowingImage();
//}