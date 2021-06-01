#include "MEE_Drawable.h"

namespace MEE
{
	void Drawable::draw() 
	{ 
		if (m_sprite) m_sprite->draw(draw_transform); 
	}

	std::weak_ptr<Sprite> Drawable::getSprite()
	{ 
		return m_sprite; 
	}

	void Drawable::setSprite(std::shared_ptr<Sprite> sprite)
	{ 
		m_sprite = sprite; 
	}

	void Drawable::setSprite(Sprite& sprite)
	{ 
		m_sprite = std::make_shared<Sprite>(sprite); 
	}
}