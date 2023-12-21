#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Smiao {
	class SM_API Log
	{
	public:
		void static Init();
		inline static std::shared_ptr<spdlog::logger>& getSmiaoLogger() { return SmiaoLogger; }
		inline static std::shared_ptr<spdlog::logger>& getAppLogger() { return AppLogger; }
	private:
		static std::shared_ptr<spdlog::logger> SmiaoLogger;
		static std::shared_ptr<spdlog::logger> AppLogger;
	};
}

#define Smiao_TRACE(...)    ::Smiao::Log::getSmiaoLogger()->trace(__VA_ARGS__)
#define Smiao_INFO(...)     ::Smiao::Log::getSmiaoLogger()->info(__VA_ARGS__)
#define Smiao_WARN(...)     ::Smiao::Log::getSmiaoLogger()->warn(__VA_ARGS__)
#define Smiao_ERROR(...)    ::Smiao::Log::getSmiaoLogger()->error(__VA_ARGS__)

#define App_TRACE(...)	      ::Smiao::Log::getAppLogger()->trace(__VA_ARGS__)
#define App_INFO(...)	      ::Smiao::Log::getAppLogger()->info(__VA_ARGS__)
#define App_WARN(...)	      ::Smiao::Log::getAppLogger()->warn(__VA_ARGS__)
#define App_ERROR(...)	      ::Smiao::Log::getAppLogger()->error(__VA_ARGS__)