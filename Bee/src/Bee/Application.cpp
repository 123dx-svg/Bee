#include "beepch.h"
#include "Application.h"
#include "Bee/Events/ApplicationEvent.h"
#include "Bee/Log.h"

namespace Bee
{

	void Application::Run()
	{

		WindowResizeEvent e(1200,720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			BEE_TRACE(e);
		}
		

		while (true);
		
	}

	Application::~Application()
	{

	}

}