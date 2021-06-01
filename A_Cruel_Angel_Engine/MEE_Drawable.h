#pragma once
#include "MEE_Sprite.h"
#include "MEE_Maths.h"
#include "MEE_Components.h"
#include <memory>

namespace MEE
{
	class Drawable
	{
	public:
		void draw();
		std::weak_ptr<Sprite> getSprite();
		void setSprite(std::shared_ptr<Sprite> sprite);
		void setSprite(Sprite& sprite);
		virtual ~Drawable() = default;
	protected:
		Drawable(Transform& transform) : m_sprite(nullptr), draw_transform(transform) {}
		Drawable(Sprite& sprite, Transform& transform) : 
			m_sprite(std::make_shared<Sprite>(sprite)), draw_transform(transform) {}
		std::shared_ptr<Sprite> m_sprite;
		Transform& draw_transform;
	};
}

