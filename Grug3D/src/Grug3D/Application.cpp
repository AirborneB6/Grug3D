#include "grugpch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"

namespace Grug3D
{
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::run()
	{
		WindowResizeEvent event(1200, 800);
		GRUG_TRACE(event);

		while (true);
	}
}
