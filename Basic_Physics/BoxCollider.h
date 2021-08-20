#pragma once
#include <MEE_Components.h>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>
#include <MEE_PluginHeader.h>
#include "BoxContactListener.h"


namespace Basic_Physics
{
	using MEE::ColliderType;
	using MEE::ColliderForm;

	class PLUGIN_EXPORT BoxCollider : public MEE::Collider
	{
	public:
		BoxCollider(b2World* world,MEE::Vector2 position = MEE::Vector2(-1000,-1000), MEE::Vector2 size = MEE::Vector2(1,1), ColliderType type = ColliderType::Static);
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
		virtual void ApplyForce(const MEE::Vector2&, const MEE::Vector2&) override;
		virtual void ApplyLinearImpulse(const MEE::Vector2& impulse, const MEE::Vector2& point);
	private:
		b2BodyDef bodyDef;
		friend class BoxContactListener;
	};
}

