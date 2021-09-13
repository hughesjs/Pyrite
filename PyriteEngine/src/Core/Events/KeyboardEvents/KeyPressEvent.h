#pragma once

#include "./KeyEvent.h"

namespace Pyrite
{
	class PYR_API KeyPressEvent : public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(KeyPress)

		KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(Repeat #:" << m_RepeatCount << ")";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	};
}
