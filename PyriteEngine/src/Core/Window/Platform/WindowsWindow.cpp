#include "pyrpch.h"
#include "./WindowsWindow.h"
#include "Core/Core.h"

namespace Pyrite::Core::Window
{
	static bool s_GLFWInitialised = false;

	Window* Window::Create(const WindowProperties& properties) //TODO - Uhhh this seems whack
	{
		return new Platform::WindowsWindow(properties);
	}
}


namespace Pyrite::Core::Window::Platform
{
	static bool s_GLFWInitialised = false;
		
	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Init(properties);
	}

	WindowsWindow::~WindowsWindow() 
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperties& properties)
	{
		m_Data.Title = properties.Title;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;

		PYR_CORE_INFO("Creating Windows Window: \"{0}\" ({1}x{2})", properties.Title, properties.Width, properties.Height);

		if (!s_GLFWInitialised)
		{
			int success = glfwInit();
			PYR_CORE_ASSERT(success, "Failed to initialise GLFW!");
			s_GLFWInitialised = true;
		}

		m_Window = glfwCreateWindow((int32_t)properties.Width, (int32_t)properties.Height, properties.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool isEnabled)
	{
		if (isEnabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSyncEnabled = isEnabled;
	}
}
