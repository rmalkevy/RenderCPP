
#include "./Primitives/Render.h"

int main()
{
	//std::shared_ptr<Window> window = std::make_shared<Window>();

	Window *window = new Window(800, 600);

	Camera *camera = new Camera(Vec3d(0, 0, -2000));
	std::list<Sphere> listObjects;
	listObjects.push_back(Sphere(Vec3d(0, 0, -100), Vec3d(255, 0, 0), 80));
	listObjects.push_back(Sphere(Vec3d(0, -100, -200), Vec3d(0, 255, 0), 100));
	listObjects.push_back(Sphere(Vec3d(100, 0, -100), Vec3d(0, 0, 255), 90));

	Light light(Vec3d(500, 400, -1000), Vec3d(255, 255, 255));
	camera->light = light;
	renderImage(*window, *camera, listObjects);
	//TODO list with 3 spheres
	return 0;
}