#pragma once

#include "../Core.h"

namespace Pyrite
{
	enum class EventType
	{
		None = 0,
		ApplicationTick, ApplicationUpdate, ApplicationRender,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
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
