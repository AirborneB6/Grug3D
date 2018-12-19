#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Grug3D
{
	class GRUG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	//To be defined in CLIENT
	Application* createApplication();
}
