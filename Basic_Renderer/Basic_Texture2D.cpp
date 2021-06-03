#include "Basic_Texture2D.h"
#include "Basic_Renderer.h"

void Basic_Texture2D::Load(const std::string& path)
{
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	width = loadedSurface->w;
	height = loadedSurface->h;

	texture = SDL_CreateTextureFromSurface(Basic_Renderer::engineRenderer, loadedSurface);
}

SDL_Texture* Basic_Texture2D::getTexture()
{
	return texture;
}
