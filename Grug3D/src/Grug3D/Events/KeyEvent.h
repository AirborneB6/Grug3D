#pragma once

#include "Event.h"

#include <sstream>

namespace Grug3D
{
	class GRUG_API KeyEvent : public Event
	{
	public:

		inline short int GetKeyCode() const { return m_KeyCode; };

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:

		//can be constructed by children only
		KeyEvent(short int keyCode) : m_KeyCode(keyCode) {}

		short int m_KeyCode;
	};

	class GRUG_API KeyPressedEvent : public KeyEvent
	{
	public:

		KeyPressedEvent(int keyCode , int repeatCount) : KeyEvent(keyCode) , m_RepeatCount(repeatCount) {}

		inline int getRepeatCount() const { return m_RepeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:

		int m_RepeatCount;

	};

	class GRUG_API KeyReleasedEvent : public KeyEvent
	{

	};
}