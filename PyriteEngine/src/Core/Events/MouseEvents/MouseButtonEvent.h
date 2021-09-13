#pragma once

#include "./MouseEvent.h"


namespace Pyrite
{
	class PYR_API MouseButtonEvent : public MouseEvent
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}
		int m_Button;
	};
}