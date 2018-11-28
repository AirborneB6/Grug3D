#include "Grug3D.h"

class Sandbox : public Grug3D::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Grug3D::Application* Grug3D::createApplication()
{
	return new Sandbox();
}