#include "BoxCollider.h"
#include <MEE_Maths.h>

Basic_Physics::BoxCollider::BoxCollider(b2World* world)
{
	MEE::Vector2& position = transform.lock()->GetPosition();
	bodyDef.position.Set(position.x, position.y);

	body = world->CreateBody(&bodyDef);
}

void Basic_Physics::BoxCollider::UpdatePosition()
{
	auto trans = transform.lock();
	auto pos = body->GetPosition();
	auto angle = body->GetAngle();

	trans->SetPosition(pos.x, pos.y);
	trans->SetRotation(angle);
}
