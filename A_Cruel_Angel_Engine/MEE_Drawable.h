#pragma once
#include "MEE_Sprite.h"
#include "MEE_Maths.h"
#include "MEE_Animation.h"
#include <memory>
#include "MEE_Exports.h"

namespace MEE
{
	class MEE_EXPORT Drawable
	{
	public:
		void Draw();
		std::weak_ptr<Sprite> GetSprite();
		void SetSprite(std::weak_ptr<Sprite> sprite);
		void SetSprite(Sprite& sprite);
		virtual ~Drawable() = default;
		void FlipHorizontally();
		void FlipVertical();
		void SetHorizontalFlip(bool val);
		void SetVerticalFlip(bool val);
	protected:
		Drawable(Transform& transform) : m_sprite(nullptr), draw_transform(transform) {}
		Drawable(Sprite& sprite, Transform& transform) : 
			m_sprite(std::make_shared<Sprite>(sprite)), draw_transform(transform) {}
		std::shared_ptr<Sprite> m_sprite;
		Transform& draw_transform;
		bool is_vertical_flipped = false;
		bool is_horizontal_flipped = false;
	};
}

