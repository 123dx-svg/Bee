#pragma once

#include "Bee/Layer.h"
#include "Bee/Events/ApplicationEvent.h"
#include "Bee/Events/KeyEvent.h"
#include "Bee/Events/MouseEvent.h"

namespace Bee
{
	class  BEE_API ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach()override;

		void OnUpdate()override ;
		void OnEvent(Event& event)override ;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);
		
		
	private:
		float m_Time = 0.0f;
	};




}
