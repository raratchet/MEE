#include "Basic_Renderer.h"
#include <MEE_Logging.h>

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
		MEE_bind_RenderDebugGrid(pl_id, "RenderDebugGrid");

		MEE_LOGGER::Log("Initilize Basic Renderer");
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
		int clipX, int clipY, int clipW, int clipH, bool h_flip, bool v_flip)
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

		SDL_RendererFlip flip = SDL_FLIP_NONE;

		if (h_flip)
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);

		if (v_flip)
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);

		Basic_Texture2D* texture = (Basic_Texture2D*)tex;

		SDL_RenderCopyEx(engineRenderer, texture->getTexture()
			,&drawRect, &srcrect, a, NULL, flip);
	}

	MEE_Texture2D CreateTexture2D(const char* path)
	{
		Basic_Texture2D* texture = new Basic_Texture2D();
		std::string s_path(path);
		texture->Load(s_path);
		return texture;
	}
	void SetRenderColor(int r, int g, int b, int a)
	{
		SDL_SetRenderDrawColor(engineRenderer, r, g, b, a);
	}

	void RenderDebugGrid()
	{
		float ppu = MEE_GetPixelsPerUnit();
		SDL_Rect viewport;
		SDL_RenderGetViewport(engineRenderer, &viewport);

		int x,y,w,h;

		x = viewport.x;
		y = viewport.y;
		w = viewport.w;
		h = viewport.h;

		SetRenderColor(200, 200, 0, 255);

		for (int i = 0; i * ppu < h + y; i++)
		{
			RenderLine(x, ppu * i + y, w + x, ppu * i + y);
		}

		for (int i = 0; i * ppu < w + x; i++)
		{
			RenderLine(ppu * i + x, y, ppu * i + x, h + y);
		}

		SetRenderColor(53, 40, 230, 255);
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
	void RenderLine(float x1, float y1, float x2, float y2)
	{
		SDL_RenderDrawLineF(engineRenderer, x1, y1, x2, y2);
	}
	void RenderPoint(float x, float y)
	{
		SDL_RenderDrawPointF(engineRenderer, x, y);
	}
	void RenderPolygon(std::vector<float> vertices)
	{
		for (int i = 0; i < vertices.size(); i += 2)
		{
			if ((i + 4) > (vertices.size()))
			{
				RenderLine(vertices[i], vertices[i + 1], vertices[0], vertices[1]);
			}
			else
			{
				RenderLine(vertices[i], vertices[i + 1], vertices[i + 2], vertices[i + 3]);
			}
		}
	}
	void RenderSolidPolygon(std::vector<float> vertices)
	{
		std::cout << "Unimplemented \n";
	}
	void RenderCircle(float xc, float yc, float radius)
	{
		float p, x, y;
		x = 0;
		y = radius;
		p = 1 - radius;


		for (int i = 0; x <= y; i++)
		{
			RenderPoint(x + xc, y + yc);
			RenderPoint(-x + xc, y + yc);
			RenderPoint(x + xc, -y + yc);
			RenderPoint(-x + xc, -y + yc);
			RenderPoint(y + xc, x + yc);
			RenderPoint(-y + xc, x + yc);
			RenderPoint(y + xc, -x + yc);
			RenderPoint(-y + xc, -x + yc);

			if (p <= 0)
			{
				x++;
				p = (2 * x) + p + 3;
			}
			else
			{
				x++;
				y--;
				p = (2 * x) - (2 * y) + p + 5;
			}

		}
	}
	void RenderSolidCircle(float x, float y, float radius)
	{
		std::cout << "Unimplemented \n";
	}
}
