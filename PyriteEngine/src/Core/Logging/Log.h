#pragma once
#include "../Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Pyrite
{
	class PYR_API Log
	{
		public:
			static void Init();
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Logging Macros
#define PYR_CORE_FATAL(...) ::Pyrite::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define PYR_CORE_ERROR(...) ::Pyrite::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PYR_CORE_WARN(...) ::Pyrite::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PYR_CORE_INFO(...) ::Pyrite::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PYR_CORE_TRACE(...) ::Pyrite::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define PYR_CLIENT_FATAL(...) ::Pyrite::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define PYR_CLIENT_ERROR(...) ::Pyrite::Log::GetClientLogger()->error(__VA_ARGS__)
#define PYR_CLIENT_WARN(...) ::Pyrite::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PYR_CLIENT_INFO(...) ::Pyrite::Log::GetClientLogger()->info(__VA_ARGS__)
#define PYR_CLIENT_TRACE(...) ::Pyrite::Log::GetClientLogger()->trace(__VA_ARGS__)