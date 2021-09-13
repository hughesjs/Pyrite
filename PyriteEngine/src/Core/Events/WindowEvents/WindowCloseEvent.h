#pragma once
#include "./WindowEvent.h"
namespace Pyrite
{
	class PYR_API WindowCloseEvent : public WindowEvent
	{
	public:
		EVENT_CLASS_TYPE(WindowClose)

		WindowCloseEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Closing";
			return ss.str();
		}
	};
}