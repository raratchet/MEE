#include "Basic_Renderer.h"


namespace Basic_Renderer
{
	void onInit(int pl_id)
	{
		MEE_SetRenderAPI(RenderAPI::SDL_Render);
		MEE_SetWindowHandlerAPI(WindowHandlerAPI::SDL);
		MEE_SetWindowName("Basic Renderer");
		MEE_bind_CreateTexture2D(pl_id,"createTexture2D");
		MEE_bind_RenderTexture2D(pl_id, "renderTexture");
	}

	void onLoad()
	{
		engineRenderer = (SDL_Renderer*)MEE_GetSDLRenderer();

		miTexture = new Basic_Texture2D();
		miTexture->Load("C:/Users/rarat/Pictures/games.png");
	}

	void onShutdown()
	{
		
	}

	void renderTexture(MEE::Texture2D* tex, float x, float y,
					   int clipX, int clipY, int clipW,
					   int clipH, float a)
	{
		SDL_Rect drawRect;
		drawRect.x = clipX;
		drawRect.y = clipY;
		drawRect.w = clipW;
		drawRect.h = clipH;
		SDL_Rect srcrect;
		srcrect.x = x;
		srcrect.y = y;
		srcrect.w = clipW;
		srcrect.h = clipH;


		Basic_Texture2D* texture = (Basic_Texture2D*)tex;

		SDL_RenderCopyEx(engineRenderer, texture->getTexture()
			,&drawRect, &srcrect, a, NULL, SDL_FLIP_NONE);
	}

	MEE_Texture2D createTexture2D(const std::string path)
	{
		Basic_Texture2D* texture = new Basic_Texture2D();
		texture->Load(path);
		return texture;
	}

	void renderQuad()
	{
		SDL_SetRenderDrawColor(engineRenderer, 100, 100, 100, 255);
		SDL_RenderDrawLineF(engineRenderer, 0, 0, 100, 100);
		renderTexture(miTexture, 10, 10, 0, 0, miTexture->getWidth(), miTexture->getHeight(), 0);
		SDL_SetRenderDrawColor(engineRenderer, 53, 40, 230, 255);
	}
}
