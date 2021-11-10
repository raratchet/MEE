/*****************************************************************//**
 * \file   MEE_Sprite.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include <memory>
#include <vector>
#include <list>
#include "MEE_Texture.h"
#include "MEE_Maths.h"
#include "MEE_Components.h"

namespace MEE
{
	class Camera;

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
		/**
		 * .
		 * 
		 * \param resource_name
		 */
		Sprite(const std::string& resource_name);

		void Draw(const Vector2& pos, const Vector2& scale, const float& rot, bool drawInPhysicalSpace);
		void Draw(const Vector2& pos, const Vector2& scale, const float& rot, bool h_flip, bool v_flip, bool drawInPhysicalSpace);

		int GetSpriteWidth();
		int GetSpriteHeight();
	private:
		int width, height;
		Vector2 baseImage_startCoord;
		std::weak_ptr<Texture2D> baseImage;
	};

	class MEE_EXPORT SpriteSheet
	{
	public:
		SpriteSheet(const std::string& resource_name, int width, int height);
		SpriteSheet(std::list<Sprite> sprites_list);
		std::weak_ptr<Sprite> operator[](int index);
		std::weak_ptr<Sprite> Get(int index);
		int GetNumberOfFrames();
	private:
		std::vector<std::shared_ptr<Sprite>> sprites;
	};
}

