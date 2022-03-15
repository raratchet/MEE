#include "MEE_Camera.h"
#include "MEE_Global.h"
#include "MEE_UI.h"

namespace MEE
{
	Camera::Camera() : position(Vector2::Zero()), m_width(0), m_heigth(0)
	{

	}

	Camera::Camera(const Vector2& pos, const int width, const int height) : position(pos), m_width(width), m_heigth(height)
	{

	}

	void Camera::DrawUIElements()
	{
		for (auto ui_ele : m_uiElements)
		{
			auto drawable = ui_ele.second;
			drawable->Draw();
		}
	}

	void Camera::SetPosition(const Vector2& pos)
	{
		position = pos;
	}

	void Camera::SetActive(bool active)
	{
        m_isActive = active;
	}

	bool Camera::GetActive()
	{
		return m_isActive;
	}

	void Camera::MakeCurrent()
	{
		//Necesit una clase viewport
		//MEE_SetRenderViewport(position.x, position.y, m_width + position.x, m_heigth + position.y);
	}
	void Camera::RemoveUIElement(const std::string& name)
	{
		m_uiElements.erase(name);
	}
	Vector2 Camera::GetPosition()
	{
		return position;
	}
}
