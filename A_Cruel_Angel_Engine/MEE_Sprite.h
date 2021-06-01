#pragma once
#include "MEE_Texture.h"
#include "MEE_Maths.h"
#include "MEE_Components.h"
#include "MEE_Graphics.h"
#include <memory>

namespace MEE
{
	class MEE_EXPORT Sprite
	{
	public:
		Sprite(std::weak_ptr<Texture2D> image, int x, int y, int w, int h);
		Sprite(const std::string& resource_name, int x, int y, int w, int h);

		void draw(const Vector2& pos, const Vector2& scale, const float& rot);
		void draw(class Transform& transform);
	private:
		int width, height;
		Vector2 startCoord;
		std::weak_ptr<Texture2D> baseImage;
	};
}

