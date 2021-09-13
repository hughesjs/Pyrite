#pragma once

#include "./MouseEvent.h"


namespace Pyrite
{
	class PYR_API MouseMovedEvent : public MouseEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseMove)

		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved: (" << m_MouseX << ";" << m_MouseY << ")";
			return ss.str();
		}

	private:
		float m_MouseX, m_MouseY;
	};
}