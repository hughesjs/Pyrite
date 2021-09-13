#pragma once
#include "./ApplicationEvent.h"
namespace Pyrite
{
	class PYR_API ApplicationRenderEvent : public ApplicationEvent
	{
	public:
		EVENT_CLASS_TYPE(ApplicationRender)

		ApplicationRenderEvent() {}		
	};
}