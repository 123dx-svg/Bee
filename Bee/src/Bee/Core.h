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
