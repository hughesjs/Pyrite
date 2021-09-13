#pragma once
#include "./ApplicationEvent.h"
namespace Pyrite
{
	class PYR_API ApplicationTickEvent : public ApplicationEvent
	{
	public:
		EVENT_CLASS_TYPE(ApplicationTick)

		ApplicationTickEvent() {}
	};
}