#include "MEE_UI.h"

MEE::UI_Element::UI_Element(): Drawable(m_transform)
{
    m_isPhysical = false;
}

void MEE::UI_Element::SetPosition(Vector2 value)
{
    m_transform.position = value;
}

void MEE::UI_Element::SetScale(Vector2 value)
{
    m_transform.scale = value;
}

void MEE::UI_Element::SetPosition(float x, float y)
{
    m_transform.position.x = x;
    m_transform.position.y = y;
}

void MEE::UI_Element::SetScale(float x, float y)
{
    m_transform.scale.x = x;
    m_transform.scale.y = y;
}

void MEE::UI_Element::SetRotation(float angle)
{
    m_transform.rotation = angle;
}

MEE::UI_Image::UI_Image(Sprite& sprite)
{
	Drawable::SetSprite(sprite);
}

MEE::UI_Image::UI_Image()
{
}
