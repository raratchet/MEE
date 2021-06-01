#pragma once
#include<iostream>
#include "MEE_Components.h"

namespace MEE
{
	//Camara concreta para el renderer de SDL
	class Camera
	{
	public:
		void setPosition(const Vector2& pos);
		void setActive(bool active);
		bool getActive();
		~Camera() { std::cout << "Se destruye camera\n"; }
	private:
		Camera();
		Camera(const Vector2& pos, const int& widht, const int& height);
		//SDL_Rect rect; //QUITA ESTO
		bool isActive = true;
		friend class Scene;
	};
}

