#include "MEE_Camera.h"
#include "MEE_Graphics.h"

//#include "Application.h"
//#include "Window.h"

namespace MEE
{
	Camera::Camera() : position(Vector2::Zero()), c_width(0), c_heigth(0)
	{

	}

	Camera::Camera(const Vector2& pos, const int width, const int height) : position(pos), c_width(width), c_heigth(height)
	{

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
		MEE_SetRenderViewport(position.x,position.y,c_width,c_heigth);
	}
}
