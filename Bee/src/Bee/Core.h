#pragma once

#ifdef BEE_PLATFORM_WINDOWS
	#ifdef BEE_BUILD_DLL
		#define BEE_API __declspec(dllexport)
	#else
		#define BEE_API __declspec(dllimport)
	#endif
#else
	#error Bee only support Windows!
		
#endif // BEE_PLATFORM_WINDOWS

#ifdef BEE_ENABLE_ASSERTS
	#define BEE_ASSERT(x,...){if(!(x)) {BEE_ERROR("Assertion failed: {0}" , __VA_ARGS__);__debugbreak();}}
	#define BEE_CORE_ASSERT(x,...){if(!(x)) {BEE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define BEE_ASSERT(x,...)
	#define BEE_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)