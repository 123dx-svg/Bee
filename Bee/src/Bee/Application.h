#pragma once
#include"Core.h"
#include"Window.h"
#include"Bee/LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get()
		{
			return *s_Instance;
		}

		inline  Window& GetWindow() {return *m_Window;}
		
		private:
		//关闭窗口事件
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<class Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		private:
		 static Application* s_Instance;
		
	};

	//在用户那边定义
	Application* CreateApplication();
}



