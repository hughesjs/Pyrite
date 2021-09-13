#pragma once

#include "../Event.h"

namespace Pyrite
{
	class PYR_API KeyEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		inline int GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {} // Note: After colon is initialiser list
		int m_KeyCode;
	};
}
