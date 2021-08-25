#include "DebugDraw.h"
#include "MEE_GLOBAL.h"
#include "MEE_Maths.h"
#include <vector>

DebugDraw::DebugDraw()
{
	this->SetFlags(e_shapeBit);
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	auto manager = MEE_GLOBAL::application->GetRenderManager().lock();

	std::vector<MEE::Vector2> vertex;
	for (int i = 0; i < vertexCount ; i ++)
	{
		b2Vec2 vec = vertices[i];
		vertex.push_back(MEE::Vector2(vec.x, vec.y));
	}
	manager->SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	//manager->SetRenderColor(0, 0, 0, 255);
	manager->RenderPolygon(vertex);
	manager->SetRenderColor(53, 40, 230, 255);

}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	auto manager = MEE_GLOBAL::application->GetRenderManager().lock();

	std::vector<MEE::Vector2> vertex;
	for (int i = 0; i < vertexCount; i++)
	{
		b2Vec2 vec = vertices[i];
		vertex.push_back(MEE::Vector2(vec.x, vec.y));
	}
	manager->SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	//manager->SetRenderColor(0, 0, 0, 255);
	manager->RenderPolygon(vertex);
	manager->SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
	auto manager = MEE_GLOBAL::application->GetRenderManager().lock();
	manager->SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	manager->RenderCircle(center.x, center.y, radius);
	manager->SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
	auto manager = MEE_GLOBAL::application->GetRenderManager().lock();
	manager->SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	manager->RenderCircle(center.x, center.y, radius);
	manager->SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	auto manager = MEE_GLOBAL::application->GetRenderManager().lock();
	manager->SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	manager->RenderLine(p1.x, p1.y, p2.x, p2.y);
	manager->SetRenderColor(53, 40, 230, 255);
}

void DebugDraw::DrawTransform(const b2Transform& xf)
{
}

void DebugDraw::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	auto manager = MEE_GLOBAL::application->GetRenderManager().lock();
	manager->SetRenderColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
	manager->RenderPoint(p.x, p.y);
	manager->SetRenderColor(53, 40, 230, 255);
}
