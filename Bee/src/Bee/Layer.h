#pragma once

#include "Bee/Core.h"
#include "Bee/Events/Event.h"

namespace Bee
{
    class BEE_API Layer
    {
    public:
        Layer(const std::string& debugName = "Layer");
        virtual ~Layer();

        virtual void OnAttach(){}
        virtual void OnDetach(){}
        virtual void OnUpdate(){}
        virtual void OnEvent(Event& event){}

        inline const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
 
}
