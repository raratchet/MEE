#include "DebugDraw.h"
#include "MEE_Graphics.h"

DebugDraw::DebugDraw()
{
	this->SetFlags(e_shapeBit);
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	int* points = new int[vertexCount * 2];

	int v = 0;
	for (int i = 0; i < vertexCount * 2; i += 2)
	{
		points[i] = vertices[v].x;
		points[i + 1] = vertices[v].y;
		v++;
	}

	MEE_RenderPolygon(points,vertexCount);
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	int* points = new int[vertexCount * 2];

	int v = 0;
	for (int i = 0; i < vertexCount * 2; i += 2)
	{
		points[i] = vertices[v].x;
		points[i + 1] = vertices[v].y;
		v++;
	}
	MEE_RenderPolygon(points, vertexCount);
}

void DebugDraw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
	MEE_RenderCircle(center.x, center.y, radius);
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
	MEE_RenderCircle(center.x, center.y, radius);
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	MEE_RenderLine(p1.x, p1.y, p2.x, p2.y);
}

void DebugDraw::DrawTransform(const b2Transform& xf)
{
}

void DebugDraw::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	MEE_RenderPoint(p.x, p.y);
}
