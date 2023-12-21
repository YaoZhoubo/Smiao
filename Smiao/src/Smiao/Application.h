#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Smiao {
	class SM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
