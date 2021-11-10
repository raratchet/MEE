#include "MEE_Camera.h"
#include "MEE_Global.h"
#include "MEE_UI.h"

namespace MEE
{
	Camera::Camera() : position(Vector2::Zero()), c_width(0), c_heigth(0)
	{

	}

	Camera::Camera(const Vector2& pos, const int width, const int height) : position(pos), c_width(width), c_heigth(height)
	{

	}

	void Camera::DrawUIElements()
	{
		for (auto ui_ele : uiElements)
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
		isActive = active;
	}

	bool Camera::GetActive()
	{
		return isActive;
	}

	void Camera::MakeCurrent()
	{
		//Necesit una clase viewport
		//MEE_SetRenderViewport(position.x, position.y, c_width + position.x, c_heigth + position.y);
	}
	void Camera::RemoveUIElement(const std::string& name)
	{
		uiElements.erase(name);
	}
	Vector2 Camera::GetPosition()
	{
		return position;
	}
}
