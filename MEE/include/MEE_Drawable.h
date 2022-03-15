/*****************************************************************//**
 * \file   MEE_Drawable.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include <memory>
#include "MEE_Sprite.h"
#include "MEE_Maths.h"
#include "MEE_Animation.h"
#include "MEE_Exports.h"

namespace MEE
{
	/**
	 * Drawable describes an object that holds a Sprite and can be drawn by the renderer.
	 */
	class MEE_EXPORT Drawable
	{
	public:
		void Draw();
		std::weak_ptr<Sprite> GetSprite();
		void SetSprite(std::weak_ptr<Sprite> sprite);
		void SetSprite(Sprite& sprite);
		void SetVisible(bool value);
		bool GetVisible();
		virtual ~Drawable() = default;
		void FlipHorizontally();
		void FlipVertical();
		void SetHorizontalFlip(bool val);
		void SetVerticalFlip(bool val);
	protected:
		Drawable(TransformComponent& transform) : m_sprite(nullptr), m_draw_transform(transform.GetTransform()) {}
		Drawable(Transform& transform) : m_sprite(nullptr), m_draw_transform(transform) {}
		Drawable(Sprite& sprite, TransformComponent& transform) :
                m_sprite(std::make_shared<Sprite>(sprite)), m_draw_transform(transform.GetTransform()) {}
		std::shared_ptr<Sprite> m_sprite;
		Transform& m_draw_transform;
		bool m_is_vertical_flipped = false;
		bool m_is_horizontal_flipped = false;
		bool m_visible = true;
		bool m_isPhysical = true;
	};
}

