#pragma once

#include "Event.h"

namespace Grug3D
{
	class GRUG_API MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(const float& x, const float& y) : m_MouseX(x) , m_MouseY(y)
		{

		}
		inline const float& getX() const
		{
			return m_MouseX;
		}
		inline const float& getY() const
		{
			return m_MouseY;
		}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << m_MouseX << " , " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:

		float m_MouseX;
		float m_MouseY;

	};

	class GRUG_API MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(const float& xOffset, const float& yOffset) : m_XOffset(xOffset), m_YOffset(yOffset)
		{

		}

		inline const float& getXOffset() const
		{
			return m_XOffset;
		}
		
		inline const float& getYOffset() const
		{
			return m_YOffset;
		}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << m_XOffset << " , " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:

		float m_XOffset;
		float m_YOffset;

	};

	//CANNOT BE INSTANTIATED
	class GRUG_API MouseButtonEvent : public Event
	{
	public:

		inline const int& getMouseButton() const
		{
			return m_Button;
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:

		MouseButtonEvent(const int& button) : m_Button(button)
		{

		}

		int m_Button;

	};

	class GRUG_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(const int& button) : MouseButtonEvent(button)
		{

		}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class GRUG_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonReleasedEvent(const int& button) : MouseButtonEvent(button)
		{

		}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}