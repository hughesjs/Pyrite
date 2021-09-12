#pragma once
#include<stdio.h>

#include "Application.h"


#ifdef PYR_PLATFORM_WINDOWS

extern Pyrite::Application* Pyrite::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to Pyrite Engine");

	auto application = Pyrite::CreateApplication();
	int returnCode = application->Run();
	delete(application);
	return returnCode;
}
#endif