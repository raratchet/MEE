#pragma once
#include <string>
#include <memory>
#include <vector>

#include "MEE_Exports.h"

namespace MEE
{
	class Texture2D;
	class Camera;
	struct Vector2;

	/**
	 * Tells if the rendering should be done relative physical postion of the camera relative to the world
	 * or should be done over the camera.
	 */
	enum class MEE_EXPORT RenderingType
	{
		Physical, NonPhysical
	};

	class MEE_EXPORT RenderingManager
	{
	public:
		void RenderClear();
		void SetRenderColor(int r, int g, int b, int a);
		void SetRenderViewport(int x, int y, int w, int h);
		void InitGL();
		void RenderLine(float x1, float y1, float x2, float y2, RenderingType type = RenderingType::Physical);
		void RenderPoint(float x, float y, RenderingType type = RenderingType::Physical);
		void RenderPolygon(const std::vector<Vector2>& vectices, RenderingType type = RenderingType::Physical);
		void RenderSolidPolygon(const std::vector<Vector2>& vectices, RenderingType type = RenderingType::Physical);
		void RenderCircle(float x, float y, float radius, RenderingType type = RenderingType::Physical);
		void RenderSolidCircle(float x, float y, float radius, RenderingType type = RenderingType::Physical);
		void RenderTexture2D(std::weak_ptr<Texture2D> texture, float x, float y, float scale_x, float scale_y, float angle,
			int clipX, int clipY, int clipW, int clipH, bool h_flip, bool v_flip, RenderingType type = RenderingType::Physical);
		Texture2D* CreateTexture2D(const std::string& path);
		void RenderDebugGrid(RenderingType type = RenderingType::Physical);
		void  SetPixelsPerUnit(float ppu);
		float GetPixelsPerUnit();
		float GetUnitsPerPixel();
		void RenderTransform(const Vector2& position);
		void SetCurrentCamera(std::weak_ptr<Camera> camera);
	private:
		std::weak_ptr<Camera> currentCamera;
		float PIXELS_PER_UNIT = 20;
		float UNITS_PER_PIXEL = 1 / PIXELS_PER_UNIT;
	};
}



