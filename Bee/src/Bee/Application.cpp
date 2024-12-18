#include "beepch.h"
#include "Application.h"

#include "Window.h"
#include "Bee/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Bee
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	void Application::Run()
	{
		
		while (m_Running)
		{
		    glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
		
		BEE_CORE_TRACE("{0}",e);
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running=false;
		return true;
	}

	Application::Application()
	{
		//初始化创建界面
		m_Window = std::unique_ptr<Window>(Window::Create());
		//设置回调函数
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

}