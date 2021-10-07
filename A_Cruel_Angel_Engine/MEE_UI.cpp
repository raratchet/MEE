#include "MEE_UI.h"

MEE::UI_Element::UI_Element(): Drawable(transform)
{
	isPhysical = false;
}

void MEE::UI_Element::SetPosition(Vector2 value)
{
	transform.position = value;
}

void MEE::UI_Element::SetScale(Vector2 value)
{
	transform.scale = value;
}

void MEE::UI_Element::SetPosition(float x, float y)
{
	transform.position.x = x;
	transform.position.y = y;
}

void MEE::UI_Element::SetScale(float x, float y)
{
	transform.scale.x = x;
	transform.scale.y = y;
}

void MEE::UI_Element::SetRotation(float angle)
{
	transform.rotation = angle;
}

MEE::UI_Image::UI_Image(Sprite& sprite)
{
	Drawable::SetSprite(sprite);
}

MEE::UI_Image::UI_Image()
{
}
