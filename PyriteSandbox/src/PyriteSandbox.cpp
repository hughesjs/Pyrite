#include <Pyrite.h>

class Sandbox : public Pyrite::Application
{
	public:
		Sandbox()
		{

		}

		~Sandbox()
		{

		}

		int Run()
		{
			return 0;
		}
};


Pyrite::Application* Pyrite::CreateApplication()
{
	return new Sandbox();
}