#pragma once

#include "Log.h"
extern Smiao::Application* Smiao::CreateApplication();

int main(int argc, char** argv)
{
	Smiao::Log::Init();
	Smiao_INFO("111111");
	App_INFO("111111");

	auto app = Smiao::CreateApplication();
	app->Run();
	delete app;
}