#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Bee
{
	class BEE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return s_ClientLogger;}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};
}

//Core log
#define BEE_CORE_TRACE(...)			::Bee::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BEE_CORE_INFO(...)			::Bee::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BEE_CORE_WARN(...)			::Bee::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BEE_CORE_ERROR(...)			::Bee::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BEE_CORE_FATAL(...)			::Bee::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client  log
#define BEE_TRACE(...)		::Bee::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BEE_INFO(...)		::Bee::Log::GetClientLogger()->info(__VA_ARGS__)
#define BEE_WARN(...)		::Bee::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BEE_ERROR(...)		::Bee::Log::GetClientLogger()->error(__VA_ARGS__)
#define BEE_FATAL(...)		::Bee::Log::GetClientLogger()->fatal(__VA_ARGS__)