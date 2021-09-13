#pragma once

#include "./MouseButtonEvent.h"


namespace Pyrite
{
	class PYR_API MouseButtonPressEvent : public MouseButtonEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseButtonRelease)

		MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released: (" << m_Button << ")";
			return ss.str();
		}
	};
}