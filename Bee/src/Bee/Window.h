#pragma once

#include "beepch.h"

#include "Bee/Core.h"
#include "Bee/Events/Event.h"

namespace Bee
{
	
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Bee Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height){}
	};

	
	//基于窗口的的接口 和平台无关
	class BEE_API Window 
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;
			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

		//窗口属性
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;
			//库不一定是glfw的库
			virtual void* GetNativeWindow() const =0;
			static Window* Create(const WindowProps& props = WindowProps());
	};







}