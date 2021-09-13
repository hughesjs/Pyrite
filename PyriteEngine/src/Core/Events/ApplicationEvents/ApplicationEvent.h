#pragma once
#include "Core/Events/Event.h"
namespace Pyrite
{
	class PYR_API ApplicationEvent : public Event
	{
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
