#pragma once

#include "Core/Logging/Log.h"
#include "Core/Application/Application.h"

#ifdef PYR_PLATFORM_WINDOWS

extern Pyrite::Application* Pyrite::CreateApplication();

int main(int argc, char** argv)
{
	Pyrite::Log::Init();
	PYR_CORE_INFO("Initialised Core Logger");
	PYR_CLIENT_INFO("Initialised Core Logger");

	auto application = Pyrite::CreateApplication();
	int returnCode = application->Run();
	delete(application);
	return returnCode;
}
#endif