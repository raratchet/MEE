#include "MEE_Camera.h"

//#include "Application.h"
//#include "Window.h"

namespace MEE
{
	Camera::Camera()
	{
		//rect.x = 0; rect.y = 0;
		//Window::GetWindowRes(&rect.w, &rect.h);
	}

	Camera::Camera(const Vector2& pos, const int& widht, const int& height)
	{
		//rect.x = pos.x; rect.y = pos.y;
		//rect.w = widht, rect.h = height;
	}

	void Camera::SetPosition(const Vector2& pos)
	{
		//rect.x = pos.x; rect.y = pos.y;
	}

	void Camera::SetActive(bool active)
	{
		isActive = active;
	}

	bool Camera::GetActive()
	{
		return isActive;
	}
}
