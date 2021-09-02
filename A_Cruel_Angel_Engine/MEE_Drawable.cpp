#include "MEE_Drawable.h"
#include "MEE_Camera.h"

namespace MEE
{
	void Drawable::Draw(std::shared_ptr<Camera> renderingCamera)
	{ 
		if (auto sprite = GetSprite().lock())
		{
			auto position = draw_transform.GetPosition();
			auto scale = draw_transform.GetScale();
			auto rot = draw_transform.GetRotation();
			sprite->Draw(renderingCamera, position, scale, rot, is_horizontal_flipped, is_vertical_flipped);
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
		visible = value;
	}
	bool Drawable::GetVisible()
	{
		return visible;
	}
	void Drawable::FlipHorizontally()
	{
		is_horizontal_flipped = !is_horizontal_flipped;
	}
	void Drawable::FlipVertical()
	{
		is_vertical_flipped = !is_vertical_flipped;
	}
	void Drawable::SetHorizontalFlip(bool val)
	{
		is_horizontal_flipped = val;
	}
	void Drawable::SetVerticalFlip(bool val)
	{
		is_vertical_flipped = val;
	}
}