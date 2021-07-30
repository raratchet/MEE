#include "Basic_Renderer.h"


namespace Basic_Renderer
{
	void OnInit(int pl_id)
	{
		MEE_SetRenderAPI(RenderAPI::SDL_Render);
		MEE_SetWindowHandlerAPI(WindowHandlerAPI::SDL);
		MEE_SetWindowName("Basic Renderer");
		MEE_bind_CreateTexture2D(pl_id,"CreateTexture2D");
		MEE_bind_RenderClear(pl_id,"RenderClear");
		MEE_bind_RenderTexture2D(pl_id,"RenderTexture");
		MEE_bind_RenderCircle(pl_id, "RenderCircle");
		MEE_bind_RenderSolidCircle(pl_id, "RenderSolidCircle");
		MEE_bind_RenderPoint(pl_id, "RenderPoint");
		MEE_bind_RenderPolygon(pl_id, "RenderPolygon");
		MEE_bind_RenderSolidPolygon(pl_id, "RenderSolidPolygon");
		MEE_bind_SetRenderColor(pl_id, "SetRenderColor");
		MEE_bind_SetRenderViewport(pl_id, "SetRenderViewport");
		MEE_bind_RenderLine(pl_id, "RenderLine");
	}

	void OnLoad()
	{
		engineRenderer = (SDL_Renderer*)MEE_GetSDLRenderer();
	}

	void OnShutdown()
	{
		
	}

	void RenderClear()
	{
		SDL_RenderClear(engineRenderer);
	}

	void RenderTexture(MEE_Texture2D tex, float x, float y, float scale_x, float scale_y, float a,
		int clipX, int clipY, int clipW, int clipH)
	{
		SDL_Rect drawRect;
		drawRect.x = clipX;
		drawRect.y = clipY;
		drawRect.w = clipW;
		drawRect.h = clipH;
		SDL_Rect srcrect;
		srcrect.x = x;
		srcrect.y = y;
		srcrect.w = clipW*scale_x;
		srcrect.h = clipH*scale_y;
		


		Basic_Texture2D* texture = (Basic_Texture2D*)tex;

		SDL_RenderCopyEx(engineRenderer, texture->getTexture()
			,&drawRect, &srcrect, a, NULL, SDL_FLIP_NONE);
	}

	MEE_Texture2D CreateTexture2D(const std::string path)
	{
		Basic_Texture2D* texture = new Basic_Texture2D();
		texture->Load(path);
		return texture;
	}
	void SetRenderColor(int r, int g, int b, int a)
	{
		SDL_SetRenderDrawColor(engineRenderer, r, g, b, a);
	}
	void SetRenderViewport(int x, int y, int w, int h)
	{
		SDL_Rect topRightViewport;
		topRightViewport.x = x;
		topRightViewport.y = y;
		topRightViewport.w = w;
		topRightViewport.h = h;
		SDL_RenderSetViewport(engineRenderer, &topRightViewport);
	}
	void RenderLine(int x1, int y1, int x2, int y2)
	{
		SDL_RenderDrawLine(engineRenderer, x1, y1, x2, y2);
	}
	void RenderPoint(int x, int y)
	{
		SDL_RenderDrawPoint(engineRenderer, x, y);
	}
	void RenderPolygon(int* vertices, int vertexCount)
	{
		std::cout << "Unimplemented \n";
	}
	void RenderSolidPolygon(int* vertices, int vertexCount)
	{
		std::cout << "Unimplemented \n";
	}
	void RenderCircle(int x, int y, int radius)
	{
		std::cout << "Unimplemented \n";
	}
	void RenderSolidCircle(int x, int y, int radius)
	{
		std::cout << "Unimplemented \n";
	}
}
