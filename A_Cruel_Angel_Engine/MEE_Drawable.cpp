#include "MEE_Drawable.h"

namespace MEE
{
	void Drawable::Draw() 
	{ 
		if (m_sprite) m_sprite->Draw(draw_transform); 
	}

	std::weak_ptr<Sprite> Drawable::GetSprite()
	{ 
		return m_sprite; 
	}

	void Drawable::SetSprite(std::shared_ptr<Sprite> sprite)
	{ 
		m_sprite = sprite; 
	}

	void Drawable::SetSprite(Sprite& sprite)
	{ 
		m_sprite = std::make_shared<Sprite>(sprite); 
	}
}