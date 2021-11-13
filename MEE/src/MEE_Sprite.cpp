#include "MEE_Sprite.h"
#include "MEE_Graphics.h"
#include "MEE_Camera.h"
#include "MEE_Global.h" // No me gusta esto

namespace MEE
{

	Sprite::Sprite(std::weak_ptr<Texture2D> image, int x, int y, int w, int h) :
		baseImage(image), width(w), height(h), baseImage_startCoord(Vector2(x, y)) {}

	Sprite::Sprite(const const char* resource_name, int x, int y, int w, int h): 
		width(w - x), height(h - y), baseImage_startCoord(Vector2(x, y))
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		baseImage = RM->Get<Texture2D>(resource_name); //No me gusta usar el global
	}

	Sprite::Sprite(const const char* resource_name)
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		baseImage = RM->Get<Texture2D>(resource_name);

		baseImage_startCoord = Vector2();

		auto bImage = baseImage.lock();
		width = bImage->GetWidth();
		height = bImage->GetHeight();
	}

	void Sprite::Draw(const Vector2& position, const Vector2& scale, const float& rot, bool drawInPhysicalSpace)
	{
		Draw(position, scale, rot, false, false, drawInPhysicalSpace);
	}

	void Sprite::Draw(const Vector2& position, const Vector2& scale, const float& rot, bool h_flip, bool v_flip, bool drawInPhysicalSpace)
	{
		if (auto image = baseImage.lock())
		{

			auto renderer = MEE_GLOBAL::application->GetRenderManager().lock();

			MEE_Texture2D texture = (MEE_Texture2D)(&*image);
			float ppu = renderer->GetPixelsPerUnit();

			float positionX_inPixels = (position.x * ppu) - ((width * scale.x) / 2);
			float positionY_inPixels = (position.y * ppu) - ((height * scale.y) / 2);

			renderer->RenderTexture2D(image, positionX_inPixels, positionY_inPixels,
				scale.x, scale.y, rot, baseImage_startCoord.x, baseImage_startCoord.y,
				width, height, h_flip, v_flip, drawInPhysicalSpace ? MEE::RenderingType::Physical : MEE::RenderingType::NonPhysical);

#ifdef _DEBUG
			renderer->RenderTransform(position);
#endif // _DEBUG

		}
	}

	int Sprite::GetSpriteWidth()
	{
		return width;
	}
	int Sprite::GetSpriteHeight()
	{
		return height;
	}

	SpriteSheet::SpriteSheet(const const char* resource_name, int width, int height)
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		auto baseImage = RM->Get<Texture2D>(resource_name); //No me gusta usar el global

		auto w = baseImage.lock()->GetWidth();
		auto h = baseImage.lock()->GetHeight();

		for (int i = 0; i < w; i += width)
			for (int j = 0; j < w; j += height)
				sprites.push_back(std::shared_ptr<Sprite>(new Sprite(baseImage, i, j, width, height)));
	}

	SpriteSheet::SpriteSheet(std::list<Sprite> sprites_list)
	{
		for (auto sprite : sprites_list)
		{
			sprites.push_back(std::make_shared<Sprite>(sprite));
		}
	}
	std::weak_ptr<Sprite> SpriteSheet::operator[](int index)
	{
		return sprites[index];
	}
	std::weak_ptr<Sprite> SpriteSheet::Get(int index)
	{
		return sprites[index];
	}
	int SpriteSheet::GetNumberOfFrames()
	{
		return sprites.size();
	}
}