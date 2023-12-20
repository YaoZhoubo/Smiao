#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Smiao {
	std::shared_ptr<spdlog::logger> Log::SmiaoLogger;
	std::shared_ptr<spdlog::logger> Log::AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		SmiaoLogger = spdlog::stdout_color_mt("Smiao");
		AppLogger = spdlog::stdout_color_mt("App");
		SmiaoLogger->set_level(spdlog::level::trace);
		AppLogger->set_level(spdlog::level::trace);
	}
}