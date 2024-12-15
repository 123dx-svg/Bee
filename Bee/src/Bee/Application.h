#pragma once
#include"Core.h"
#include"Events/Event.h"

namespace Bee 
{

	class BEE_API Application
	{
	 public:
		Application();
		virtual ~Application();

		void Run();

		private:
		std::unique_ptr<class Window> m_Window;
		bool m_Running = true;
		
	};

	//在用户那边定义
	Application* CreateApplication();
}



