#include <Smiao.h>

class Sandbox : public Smiao::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Smiao::Application* Smiao::CreateApplication()
{
	return new Sandbox();
}