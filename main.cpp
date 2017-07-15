
#include "./Primitives/Render.h"

int main()
{
	//std::shared_ptr<Window> window = std::make_shared<Window>();

	Window *window = new Window(800, 600);
	Camera *camera = new Camera(Vec3d(0, 0, -2000));
	//Sphere sphere();
	//TODO list with 3 spheres
	return 0;
}