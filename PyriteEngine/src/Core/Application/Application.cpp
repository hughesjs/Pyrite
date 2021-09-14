#include "pyrpch.h"
#include "Application.h"
#include "Core/Window/Window.h"


namespace Pyrite
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Core::Window::Window>(Core::Window::Window::Create());
	}

	Application::~Application()
	{

	}

	int Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
		return 0;
	}
}