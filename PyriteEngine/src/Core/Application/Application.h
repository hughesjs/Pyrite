#pragma once

#include "Core/core.h"
#include "Core/Window/Window.h"

namespace Pyrite
{
	class PYR_API Application
	{
		public:
			Application();
			virtual ~Application();
			int Run();
		private:
			std::unique_ptr<Core::Window::Window> m_Window;
			bool m_Running = true;
	};

	//Defined in client
	Application* CreateApplication();
}


