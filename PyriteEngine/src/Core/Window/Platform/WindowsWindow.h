#pragma once
#include "pyrpch.h"
#include "Core/Core.h"
#include "Core/Window/Window.h"

#include "GLFW/glfw3.h"


namespace Pyrite::Core::Window::Platform
{
	class WindowsWindow : public Pyrite::Core::Window::Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width;	}
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool isEnabled) override;
		bool IsVSyncEnabled() const override { return m_Data.VSyncEnabled;	}

	private:

		virtual void Init(const WindowProperties& properties);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSyncEnabled;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};
}