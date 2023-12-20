#pragma once

#include "Core.h"

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
