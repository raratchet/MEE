#include "MEE_Drawable.h"

namespace MEE
{
	void Drawable::Draw() 
	{ 
		if (auto sprite = GetSprite().lock())
		{
			auto position = draw_transform.GetPosition();
			auto scale = draw_transform.GetScale();
			auto rot = draw_transform.GetRotation();
			sprite->Draw(position,scale,rot);
		}
	}

	std::weak_ptr<Sprite> Drawable::GetSprite()
	{ 
		return m_sprite; 
	}

	void Drawable::SetSprite(std::weak_ptr<Sprite> sprite)
	{ 
		m_sprite = sprite.lock(); 
	}

	void Drawable::SetSprite(Sprite& sprite)
	{ 
		m_sprite = std::make_shared<Sprite>(sprite); 
	}
}