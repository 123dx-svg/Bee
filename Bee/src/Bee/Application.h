#pragma once
#include"Core.h"
#include"Events/Event.h"

namespace Bee 
{

	class BEE_API Application
	{
	 public:
		void Run();

		virtual ~Application();
	};

	//在用户那边定义
	Application* CreateApplication();
}



