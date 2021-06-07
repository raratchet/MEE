#include "Basic_Renderer.h"


namespace Basic_Renderer
{
	void OnInit(int pl_id)
	{
		MEE_SetRenderAPI(RenderAPI::SDL_Render);
		MEE_SetWindowHandlerAPI(WindowHandlerAPI::SDL);
		MEE_SetWindowName("Basic Renderer");
		MEE_bind_CreateTexture2D(pl_id,"createTexture2D");
		MEE_bind_RenderTexture2D(pl_id, "renderTexture");
	}

	void OnLoad()
	{
		engineRenderer = (SDL_Renderer*)MEE_GetSDLRenderer();

		miTexture = new Basic_Texture2D();
		miTexture->Load("C:/Users/rarat/Pictures/games.png");
	}

	void OnShutdown()
	{
		
	}

	void renderTexture(MEE_Texture2D tex, float x, float y,
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
}
