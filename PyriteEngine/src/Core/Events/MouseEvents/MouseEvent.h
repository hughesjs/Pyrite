#pragma once
#include "../Event.h"

namespace Pyrite
{
	class MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};
}