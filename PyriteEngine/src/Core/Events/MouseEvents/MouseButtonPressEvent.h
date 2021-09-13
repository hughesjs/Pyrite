#pragma once

#include "./MouseButtonEvent.h"


namespace Pyrite
{
	class PYR_API MouseButtonPressEvent : public MouseButtonEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseButtonPress)

		MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed: (" << m_Button << ")";
			return ss.str();
		}
	};
}