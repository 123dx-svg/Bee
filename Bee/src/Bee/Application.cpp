#include "beepch.h"
#include "Application.h"

#include "Window.h"
#include "Bee/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Bee
{

	void Application::Run()
	{
		
		while (m_Running)
		{
		    glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		
	}

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

}