/*****************************************************************//**
 * \file   MEE_UI.h
 * \brief  Contains UI_Elements and it's children
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include "MEE_Exports.h"
#include "MEE_Drawable.h"

namespace MEE
{
	class MEE_EXPORT UI_Element : public Drawable
	{
	public:
		UI_Element();
		virtual ~UI_Element() = default;
		void SetPosition(Vector2 value);
		void SetScale(Vector2 value);
		void SetPosition(float x, float y);
		void SetScale(float x, float y);
		void SetRotation(float angle);
	private:
		//Camera& targetCamera;
		Transform m_transform;

		friend class Camera;
	};

	class MEE_EXPORT UI_Image : public UI_Element
	{
	public:
		UI_Image(Sprite& sprite);
		UI_Image();
		//UI_Image(const std::string& resourceName); // Lo implemento m�s adelante
	};
}


