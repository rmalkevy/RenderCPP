
#include "includes/Render.h"

int main()
{
	//std::shared_ptr<Window> window = std::make_shared<Window>();

	Window *window = new Window(800, 600);

	Light light(Vec3d(500, 400, -1000), Vec3d(1, 1, 1));
	Camera *camera = new Camera(Vec3d(0, 0, -2000), light);
	std::list< IPrimitive*> listObjects;
//    IPrimitive *iPrimitive1 = new Sphere(Vec3d(0, 0, -100), Vec3d(1, 0, 0), 80);
//    IPrimitive *iPrimitive2 = new Sphere(Vec3d(0, -100, -200), Vec3d(0, 1, 0), 100);
//    IPrimitive *iPrimitive3 = new Sphere(Vec3d(100, 0, -100), Vec3d(0, 0, 1), 90);

    listObjects.push_back(new Sphere(Vec3d(0, 0, -100), Vec3d(1, 0, 0), 80));
    listObjects.push_back(new Sphere(Vec3d(0, -100, -200), Vec3d(0, 1, 0), 100));
    listObjects.push_back(new Sphere(Vec3d(100, 0, -100), Vec3d(0, 0, 1), 90));


//	listObjects.push_back(Sphere(Vec3d(0, 0, -100), Vec3d(1, 0, 0), 80));
//	listObjects.push_back(Sphere(Vec3d(0, -100, -200), Vec3d(0, 1, 0), 100));
//	listObjects.push_back(Sphere(Vec3d(100, 0, -100), Vec3d(0, 0, 1), 90));

	renderImage(*window, *camera, listObjects);
	//TODO list with 3 spheres
	return 0;
}