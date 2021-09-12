#pragma once

#ifdef PYR_PLATFORM_WINDOWS
	#ifdef PYR_BUILD_DLL
		#define PYR_API _declspec(dllexport)
	#else
		#define PYR_API _declspec(dllimport)
	#endif // PYR_BUILD_DLL
#else
	#error Windows is currently the only supported platform...
#endif