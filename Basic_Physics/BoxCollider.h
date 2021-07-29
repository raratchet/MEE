#pragma once
#include <MEE_Components.h>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>



namespace Basic_Physics
{
	using MEE::ColliderType;
	using MEE::ColliderForm;

	class BoxCollider : MEE::Collider
	{
	public:
		BoxCollider(b2World* world);
		void UpdatePosition();
		b2Body* body;
		virtual MEE::Vector2 GetVelocity() override;
		virtual float GetFriction() override;
		virtual float GetGravity() override;
		virtual bool GetRotationConstrait() override;
		virtual bool GetActive() override;
		virtual ColliderType GetType() override;
		virtual ColliderForm GetFigure() override;
		virtual void SetVelocity(const MEE::Vector2&) override;
		virtual void SetFriction(float) override;
		virtual void SetGravity(float) override;
		virtual void SetRotationConstrait(bool) override;
		virtual void SetActive(bool) override;
		virtual void SetType(ColliderType) override;
		virtual void SetFigure(ColliderForm) override;
	private:
		b2BodyDef bodyDef;
	};
}

