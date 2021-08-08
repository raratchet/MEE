#include "DebugDraw.h"
#include "MEE_Graphics.h"

DebugDraw::DebugDraw()
{
	this->SetFlags(e_shapeBit);
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	float* points = new float[vertexCount * 2];
	float ppu = MEE_GetPixelsPerUnit();
	int v = 0;
	for (int i = 0; i < vertexCount * 2; i += 2)
	{
		points[i] = vertices[v].x * ppu;
		points[i + 1] = vertices[v].y * ppu;
		v++;
	}
	//MEE_SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	MEE_SetRenderColor(0, 0, 0, 255);
	MEE_RenderPolygon(points, vertexCount);
	MEE_SetRenderColor(53, 40, 230, 255);

	delete[] points;
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	float* points = new float[vertexCount * 2];
	float ppu = MEE_GetPixelsPerUnit();
	int v = 0;
	for (int i = 0; i < vertexCount * 2; i += 2)
	{
		points[i] = vertices[v].x * ppu;
		points[i + 1] = vertices[v].y * ppu ;
		v++;
	}
	//MEE_SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	MEE_SetRenderColor(0, 0, 0, 255);
	MEE_RenderPolygon(points, vertexCount);
	MEE_SetRenderColor(53, 40, 230, 255);

	delete[] points;
}

void DebugDraw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
	MEE_SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	MEE_RenderCircle(center.x, center.y, radius);
	MEE_SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
	MEE_SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	MEE_RenderCircle(center.x, center.y, radius);
	MEE_SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	MEE_SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	MEE_RenderLine(p1.x, p1.y, p2.x, p2.y);
	MEE_SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawTransform(const b2Transform& xf)
{
}

void DebugDraw::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	MEE_SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	MEE_RenderPoint(p.x, p.y);
	MEE_SetRenderColor(53, 40, 230, 255);
}
