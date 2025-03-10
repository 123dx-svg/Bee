#include "beepch.h"
#include "Application.h"

#include "Window.h"
#include "Bee/Events/ApplicationEvent.h"
#include <glad/glad.h>

#include "Input.h"

namespace Bee
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	 Application* Application::s_Instance = nullptr;
	
	void Application::Run()
	{
		
		while (m_Running)
		{
		    glClearColor(0,1,0,1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			
			//鼠标轮询测试
			auto[x,y] = Input::GetMousePosition();
			BEE_CORE_TRACE("{0},{1}",x,y);

			m_Window->OnUpdate();
		}
		
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
		
		//BEE_CORE_TRACE("{0}",e);此处app通过层调用过了

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running=false;
		return true;
	}

	Application::Application()
	{
		s_Instance= this;
		//初始化创建界面
		m_Window = std::unique_ptr<Window>(Window::Create());
		//设置回调函数
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		unsigned int id;
		glGenVertexArrays(1,&id);
	}

	Application::~Application()
	{

	}

}