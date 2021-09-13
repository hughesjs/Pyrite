#pragma once
#include "MouseEvent.h"
namespace Pyrite
{
	class PYR_API MouseScrollEvent : public MouseEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseScroll)

			MouseScrollEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetX() const { return m_XOffset; }
		inline float GetY() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled: (" << m_XOffset << ";" << m_YOffset << ")";
			return ss.str();
		}

	private:
		float m_XOffset, m_YOffset;
	};
}