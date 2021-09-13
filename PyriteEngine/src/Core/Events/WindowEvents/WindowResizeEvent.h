#pragma once
#include "./WindowEvent.h"
namespace Pyrite
{
	class PYR_API WindowResizeEvent : public WindowEvent
	{
	public:
		EVENT_CLASS_TYPE(WindowResize)

		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}
	private:
		unsigned int m_Width, m_Height;
	};
}