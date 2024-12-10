#pragma once
#include"Core.h"

namespace Bee 
{

	class BEE_API Application
	{
	 public:
		void Run();

		virtual ~Application();
	};

	Application* CreateApplication();
}



