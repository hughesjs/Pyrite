#pragma once
#include "Core/Events/Event.h"
namespace Pyrite
{
	class PYR_API WindowEvent : public Event
	{
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};
}