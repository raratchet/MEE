#include "MEE_Drawable.h"
#include "MEE_Camera.h"

namespace MEE
{
	void Drawable::Draw()
	{ 
		if (auto sprite = GetSprite().lock())
		{
			auto position = m_draw_transform.position;
			auto scale = m_draw_transform.scale;
			auto rot = m_draw_transform.rotation;
			sprite->Draw(position, scale, rot, m_is_horizontal_flipped, m_is_vertical_flipped, m_isPhysical);
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
	void Drawable::SetVisible(bool value)
	{
        m_visible = value;
	}
	bool Drawable::GetVisible()
	{
		return m_visible;
	}
	void Drawable::FlipHorizontally()
	{
        m_is_horizontal_flipped = !m_is_horizontal_flipped;
	}
	void Drawable::FlipVertical()
	{
        m_is_vertical_flipped = !m_is_vertical_flipped;
	}
	void Drawable::SetHorizontalFlip(bool val)
	{
        m_is_horizontal_flipped = val;
	}
	void Drawable::SetVerticalFlip(bool val)
	{
        m_is_vertical_flipped = val;
	}
}