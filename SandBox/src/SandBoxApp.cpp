#include <Bee.h>


class ExampleLayer :public Bee::Layer
{
	public:
		ExampleLayer()
			:Layer("Example")
		{
			
		}

	void OnUpdate() override
		{
			BEE_INFO("ExampleLayer::OnUpdate");
		}
	
	void OnEvent(Bee::Event& event) override
		{
			BEE_TRACE("{0}", event);
		}
		
};


class SandBox :public Bee::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}
};


Bee::Application* Bee::CreateApplication()
{
	return new SandBox();
}