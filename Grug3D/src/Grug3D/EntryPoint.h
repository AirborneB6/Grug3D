#pragma once

#ifdef GRUG_PLATFORM_WINDOWS

extern Grug3D::Application* Grug3D::createApplication();

int main(int argc, char** argv)
{
	printf("Grug engine starting...\n");

	Grug3D::Application* app = Grug3D::createApplication();

	printf("Grug ready for work!");

	app->run();

	delete app;
}

#endif // GRUG_PLATFORM_WINDOWS
