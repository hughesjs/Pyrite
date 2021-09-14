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

#ifdef PYR_ENABLE_ASSERTIONS
	#define PYR_ASSERT(x, ...) { if(!(x)) { PYR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PYR_CORE_ASSERT(x, ...) { if(!(x)) { PYR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PYR_ASSERT(x, ...)
	#define PYR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#define SET_BIT(x, y) (x | (1 << y))
#define BIT_IS_SET(x, y) (x & y)
