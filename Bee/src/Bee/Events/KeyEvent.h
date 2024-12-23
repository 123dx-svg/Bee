﻿#pragma once

#include "Event.h"

namespace Bee
{
    //部分虚函数没实现依旧是抽象类
    class BEE_API KeyEvent:public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
        
    protected:
        KeyEvent(int keyCode):m_KeyCode(keyCode) {}
        //按键代号
        int m_KeyCode;
        
    };

    class BEE_API KeyPressedEvent:public KeyEvent
    {
        public:
            KeyPressedEvent(int keyCode,int repeatCount):KeyEvent(keyCode),m_RepeatCount(repeatCount){}

            inline int GetRepeatCount() const { return m_RepeatCount; }
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
                return ss.str();
            }
            EVENT_CLASS_TYPE(KeyPressed)
    
        private:
            //长按
            int m_RepeatCount;
        
    };

    class BEE_API KeyReleasedEvent:public KeyEvent
    {
        public:
            KeyReleasedEvent(int keyCode):KeyEvent(keyCode){}
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << m_KeyCode;
                return ss.str();
            }
            EVENT_CLASS_TYPE(KeyReleased)

      
    };

    class BEE_API KeyTypedEvent:public KeyEvent
    {
        public:
            KeyTypedEvent(int keyCode):KeyEvent(keyCode){}
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyTypedEvent: " << m_KeyCode;
                return ss.str();
            }
            EVENT_CLASS_TYPE(KeyTyped)

    };
    
    
}
