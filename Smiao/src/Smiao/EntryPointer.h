#pragma once

extern Smiao::Application* Smiao::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Smiao::CreateApplication();
	app->Run();
	delete app;
}