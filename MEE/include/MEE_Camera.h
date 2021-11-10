/*****************************************************************//**
 * \file   MEE_Camera.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include<iostream>
#include "MEE_Components.h"
#include "MEE_UI.h"

namespace MEE
{
	class Scene;
	class UI_Element;

	class MEE_EXPORT Camera
	{
	public:
		void SetPosition(const Vector2& pos);
		void SetActive(bool active);
		bool GetActive();
		void MakeCurrent();
		template<class T = UI_Element, class ...Args>
		T& AttachUIElement(const std::string& name, Args...);
		void RemoveUIElement(const std::string& name);
		Vector2 GetPosition();
		~Camera() = default;
	private:
		Camera();
		Camera(const Vector2& pos, const int width, const int height);
		void DrawUIElements();
		Vector2 position;
		int c_width, c_heigth;
		bool isActive = true;
		std::map<std::string, std::shared_ptr<UI_Element>> uiElements;
		friend class Scene;
	};

	template <class T, class ...Args>
	T& Camera::AttachUIElement(const std::string& name, Args... args)
	{
		T* element = new T((std::forward<Args>(args), ...));
		uiElements.insert({ name, std::shared_ptr<T>(element) });
		return *element;
	}
}

