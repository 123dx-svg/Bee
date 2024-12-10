#include <Bee.h>

class SandBox :public Bee::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};


Bee::Application* Bee::CreateApplication()
{
	return new SandBox();
}