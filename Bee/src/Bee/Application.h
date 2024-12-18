#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Bee/Events/ApplicationEvent.h"

namespace Bee 
{

	class BEE_API Application
	{
	 public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		private:
		//关闭窗口事件
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<class Window> m_Window;
		bool m_Running = true;
		
	};

	//在用户那边定义
	Application* CreateApplication();
}



