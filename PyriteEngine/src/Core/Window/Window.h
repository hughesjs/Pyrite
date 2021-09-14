#pragma once
#include "pyrpch.h"
#include "Core/Core.h"
#include "Core/Events/Event.h"

#include "WindowProperties.h"

namespace Pyrite::Core::Window
{
	class PYR_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Pyrite::Event&)>;

		virtual ~Window() {};
		virtual void OnUpdate() {};

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool isEnabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}