#pragma once
#include<SDL_render.h>
#include<MEE_Texture.h>

class Basic_Texture2D : public MEE::Texture2D
{
public:
	Basic_Texture2D() = default;
	virtual ~Basic_Texture2D() = default;
	virtual void load(const std::string & path) override;
	SDL_Texture* getTexture();
private:
	SDL_Texture* texture;
};

