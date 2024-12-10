#pragma once


#ifdef BEE_PLATFORM_WINDOWS

extern Bee::Application* Bee::CreateApplication();

int main(int argc, char** argv)
{
	printf("Bee Engine\n");
	auto app = Bee::CreateApplication();
	app->Run();
	delete app;
	

}


#endif