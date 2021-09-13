#pragma once

#include "./KeyEvent.h"

namespace Pyrite
{
	class PYR_API KeyReleaseEvent : public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(KeyRelease)

		KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_KeyCode;
			return ss.str();
		}
	};
}
