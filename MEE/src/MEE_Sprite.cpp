#include "MEE_Sprite.h"
#include "MEE_Graphics.h"
#include "MEE_Camera.h"
#include "MEE_Global.h" // No me gusta esto

namespace MEE
{

	Sprite::Sprite(std::weak_ptr<Texture2D> image, int x, int y, int w, int h) :
            m_baseImage(image), m_width(w), m_height(h), m_baseImageStartCoord(Vector2(x, y)) {}

	Sprite::Sprite(const std::string& resource_name, int x, int y, int w, int h):
            m_width(w - x), m_height(h - y), m_baseImageStartCoord(Vector2(x, y))
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

        m_baseImage = RM->Get<Texture2D>(resource_name); //No me gusta usar el global
	}

	Sprite::Sprite(const std::string& resource_name)
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

        m_baseImage = RM->Get<Texture2D>(resource_name);

        m_baseImageStartCoord = Vector2();

		auto bImage = m_baseImage.lock();
        m_width = bImage->GetWidth();
        m_height = bImage->GetHeight();
	}

	void Sprite::Draw(const Vector2& position, const Vector2& scale, const float& rot, bool drawInPhysicalSpace)
	{
		Draw(position, scale, rot, false, false, drawInPhysicalSpace);
	}

	void Sprite::Draw(const Vector2& position, const Vector2& scale, const float& rot, bool h_flip, bool v_flip, bool drawInPhysicalSpace)
	{
		if (auto image = m_baseImage.lock())
		{

			auto renderer = MEE_GLOBAL::application->GetRenderManager().lock();

			MEE_Texture2D texture = (MEE_Texture2D)(&*image);
			float ppu = renderer->GetPixelsPerUnit();

			float positionX_inPixels = (position.x * ppu) - ((m_width * scale.x) / 2);
			float positionY_inPixels = (position.y * ppu) - ((m_height * scale.y) / 2);

			renderer->RenderTexture2D(image, positionX_inPixels, positionY_inPixels,
                                      scale.x, scale.y, rot, m_baseImageStartCoord.x, m_baseImageStartCoord.y,
                                      m_width, m_height, h_flip, v_flip, drawInPhysicalSpace ? MEE::RenderingType::Physical : MEE::RenderingType::NonPhysical);

#ifdef _DEBUG
			renderer->RenderTransform(position);
#endif // _DEBUG

		}
	}

	int Sprite::GetSpriteWidth()
	{
		return m_width;
	}
	int Sprite::GetSpriteHeight()
	{
		return m_height;
	}

	SpriteSheet::SpriteSheet(const std::string& resource_name, int width, int height)
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		auto baseImage = RM->Get<Texture2D>(resource_name); //No me gusta usar el global

		auto w = baseImage.lock()->GetWidth();
		auto h = baseImage.lock()->GetHeight();

		for (int i = 0; i < w; i += width)
			for (int j = 0; j < w; j += height)
				m_sprites.push_back(std::shared_ptr<Sprite>(new Sprite(baseImage, i, j, width, height)));
	}

	SpriteSheet::SpriteSheet(std::list<Sprite> sprites_list)
	{
		for (auto sprite : sprites_list)
		{
			m_sprites.push_back(std::make_shared<Sprite>(sprite));
		}
	}
	std::weak_ptr<Sprite> SpriteSheet::operator[](int index)
	{
		return m_sprites[index];
	}
	std::weak_ptr<Sprite> SpriteSheet::Get(int index)
	{
		return m_sprites[index];
	}
	int SpriteSheet::GetNumberOfFrames()
	{
		return m_sprites.size();
	}
}