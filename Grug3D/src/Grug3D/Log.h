#pragma once

#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Grug3D
{
	class GRUG_API Log
	{
	public:
		Log();
		~Log();

		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};
}

#define GRUG_CORE_ERROR(...) ::Grug3D::Log::getCoreLogger()->error(__VA_ARGS__)
#define GRUG_CORE_WARN(...) ::Grug3D::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GRUG_CORE_INFO(...) ::Grug3D::Log::getCoreLogger()->info(__VA_ARGS__)
#define GRUG_CORE_TRACE(...) ::Grug3D::Log::getCoreLogger()->trace(__VA_ARGS__)






