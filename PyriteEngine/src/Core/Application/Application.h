#pragma once

#include "Core/core.h"

namespace Pyrite
{
	class PYR_API Application
	{
		public:
			Application();
			virtual ~Application();
			int Run();
	};

	//Defined in client
	Application* CreateApplication();
}


