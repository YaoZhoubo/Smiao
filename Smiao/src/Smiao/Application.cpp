#include "Application.h"

#include "Events/AppEvent.h"
#include "Events/KeyEvent.h"
#include "Log.h"
namespace Smiao {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		KeyPressedEvent e2(1, 5);
		if (e.IsInCategory(EventCategoryApplication))
		{
			Smiao_TRACE(e);
		}
		Smiao_TRACE(e2.GetCategoryFlags());
		while (true)
		{
		}
	}
}