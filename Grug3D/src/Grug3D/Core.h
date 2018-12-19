#pragma once

#ifdef GRUG_PLATFORM_WINDOWS
	#ifdef GRUG_BUILD_DLL
		#define GRUG_API __declspec(dllexport)
	#else
		#define GRUG_API __declspec(dllimport)
	#endif // GRUG_BUILD_DLL

#else
	#error Grug only uses Windows!
#endif // GRUG_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
