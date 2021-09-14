#pragma once
#include "pyrpch.h"

namespace Pyrite::Core::Window
{
	struct WindowProperties
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(const std::string& title = "Pyrite Engine", uint32_t width = 1280, uint32_t height = 720) : Title(title), Width(width), Height(height) {}
	};
}

