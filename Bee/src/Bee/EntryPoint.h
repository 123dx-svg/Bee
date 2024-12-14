#pragma once


#ifdef BEE_PLATFORM_WINDOWS

extern Bee::Application* Bee::CreateApplication();

int main(int argc, char** argv)
{
	Bee::Log::Init();
	BEE_CORE_WARN("initial Log!!");
	int a =5;
	BEE_INFO("Hello Var={0}",a); 



	auto app = Bee::CreateApplication();
	app->Run();
	delete app;
	
}


#endif