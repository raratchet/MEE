#include "BoxCollider.h"
#include <MEE_Maths.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>

Basic_Physics::BoxCollider::BoxCollider(b2World* world)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0, 0);

	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
}

void Basic_Physics::BoxCollider::UpdatePosition()
{
	auto trans = transform.lock();
	auto pos = body->GetPosition();
	auto angle = body->GetAngle();

	trans->SetPosition(pos.x, pos.y);
	trans->SetRotation(angle);
}
