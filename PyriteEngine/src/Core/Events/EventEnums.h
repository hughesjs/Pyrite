#pragma once

#include "../Core.h"

namespace Pyrite
{
	enum class EventType
	{
		None = 0,
		AppTick, AppUpdate, AppRender,
		WindowClose, WindowOpen, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
		KeyPress, KeyRelease,
		MouseClickPress, MouseClickRelease, MouseMove, MouseSroll
	};

	enum EventCategory // Has to be a C style enum so we can use bitflags
	{
		None = 0,
		EventCategoryApplication = BIT(1),
		EventCategoryWindow = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryInput = BIT(5)
	};

	
}
