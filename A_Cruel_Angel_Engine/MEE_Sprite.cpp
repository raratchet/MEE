#include "MEE_Sprite.h"


#include "MEE_Global.h" // No me gusta esto

namespace MEE
{

	Sprite::Sprite(std::weak_ptr<Texture2D> image, int x, int y, int w, int h) :
		baseImage(image), width(w), height(h), startCoord(Vector2(x, y)) {}

	Sprite::Sprite(const std::string& resource_name, int x, int y, int w, int h): 
		width(w), height(h), startCoord(Vector2(x, y))
	{
		auto RM =MEE_GLOBAL::application->getResourceManager().lock();

		baseImage = RM->get<Texture2D>(resource_name); //No me gusta usar el global
	}

	void Sprite::draw(const Vector2& pos, const Vector2& scale, const float& rot)
	{
	}

	void Sprite::draw(Transform& transform)
	{
		Vector2& position = transform.getPosition();
		float& rot = transform.getRotation();
		if (auto image = baseImage.lock())
			MEE_renderTexture2D(
				*image,
				position.x,
				position.y,
				startCoord.x,
				startCoord.y,
				width,
				height,
				rot);
	}
}