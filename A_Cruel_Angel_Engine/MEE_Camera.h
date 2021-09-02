#pragma once
#include<iostream>
#include "MEE_Components.h"

namespace MEE
{
	class Scene;

	class MEE_EXPORT Camera
	{
	public:
		void SetPosition(const Vector2& pos);
		void SetActive(bool active);
		bool GetActive();
		void MakeCurrent();
		Vector2 GetPosition();
		~Camera() = default;
	private:
		Camera();
		Camera(const Vector2& pos, const int width, const int height);
		Vector2 position;
		int c_width, c_heigth;
		bool isActive = true;
		friend class Scene;
	};
}

