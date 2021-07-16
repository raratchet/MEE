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
		/**
		 * Default constructur for Sprite class.
		 * 
		 * \param image: A pointer to the base image for the sprite.
		 * \param x : X position in the image.
		 * \param y : Y position in the image.
		 * \param w : W clip position in the image.
		 * \param h : H clip position in the image.
		 */
		Sprite(std::weak_ptr<Texture2D> image, int x, int y, int w, int h);
		/**
		 * Default constructur for Sprite class.
		 * 
		 * \param resource_name: The resourceManager indentifier for the base image 
		 *  for the sprite.
		 * \param x : X start position in the image.
		 * \param y : Y start position in the image.
		 * \param w : W clip position in the image.
		 * \param h : H clip position in the image.
		 */
		Sprite(const std::string& resource_name, int x, int y, int w, int h);

		void Draw(const Vector2& pos, const Vector2& scale, const float& rot);
		void Draw(class Transform& transform);
	private:
		int width, height;
		Vector2 startCoord;
		std::weak_ptr<Texture2D> baseImage;
	};
}

