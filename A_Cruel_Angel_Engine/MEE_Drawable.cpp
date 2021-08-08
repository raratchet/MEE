#include "MEE_Drawable.h"

namespace MEE
{
	void Drawable::Draw() 
	{ 
		if (m_sprite)
		{
			auto position = draw_transform.GetPosition(); //QUE PUTAS HACES? NO SE DIVIDE ENTRE DOS LA POSICION SI NO SE RESTA LA MITAD DEL WIDTH
			auto scale = draw_transform.GetScale();
			auto rot = draw_transform.GetRotation();
			m_sprite->Draw(position,scale,rot);
		}
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