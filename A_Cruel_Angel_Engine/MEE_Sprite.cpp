#include "MEE_Sprite.h"
#include "MEE_Graphics.h"

#include "MEE_Global.h" // No me gusta esto

namespace MEE
{



	Sprite::Sprite(std::weak_ptr<Texture2D> image, int x, int y, int w, int h) :
		baseImage(image), width(w), height(h), baseImage_startCoord(Vector2(x, y)) {}

	Sprite::Sprite(const std::string& resource_name, int x, int y, int w, int h): 
		width(w), height(h), baseImage_startCoord(Vector2(x, y))
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		baseImage = RM->Get<Texture2D>(resource_name); //No me gusta usar el global
	}

	Sprite::Sprite(const std::string& resource_name)
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		baseImage = RM->Get<Texture2D>(resource_name);

		baseImage_startCoord = Vector2();

		auto bImage = baseImage.lock();
		width = bImage->getWidth();
		height = bImage->getHeight();
	}

	void Sprite::Draw(const Vector2& position, const Vector2& scale, const float& rot)
	{
		if (auto image = baseImage.lock())
		{

			MEE_Texture2D texture = (MEE_Texture2D)(&*image);
			float ppu = MEE_GetPixelsPerUnit();

			float positionX_inPixels = (position.x * ppu) - ((width * scale.x) / 2);
			float positionY_inPixels = (position.y * ppu) - ((height * scale.y) / 2);

			MEE_RenderTexture2D(texture,positionX_inPixels,positionY_inPixels, 
								scale.x,scale.y,rot,
								baseImage_startCoord.x,baseImage_startCoord.y,width,height);
#ifdef _DEBUG
			MEE_SetRenderColor(0, 255, 0, 255);
			const float radius = 1.0F;
			MEE_RenderCircle((position.x * ppu), (position.y * ppu), radius);	
			MEE_SetRenderColor(53, 40, 230, 255);
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

	SpriteSheet::SpriteSheet(const std::string& resource_name, int width, int height)
	{
		auto RM = MEE_GLOBAL::application->GetResourceManager().lock();

		auto baseImage = RM->Get<Texture2D>(resource_name); //No me gusta usar el global

		auto w = baseImage.lock()->getWidth();
		auto h = baseImage.lock()->getHeight();

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