#pragma once
#include "./ApplicationEvent.h"
namespace Pyrite
{
	class PYR_API ApplicationUpdateEvent : public ApplicationEvent
	{
	public:
		EVENT_CLASS_TYPE(ApplicationUpdate)

		ApplicationUpdateEvent() {}
	};
}