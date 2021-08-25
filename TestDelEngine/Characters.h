#pragma once
#include "MEG_Game.h"
#include "MEG_Input.h"

class BaseCharacter : public Behaviour
{
protected:
	bool running = false;
	float maxVelocity = 6;
	float runVelocity = 1;
	float jumpHeight = 6;
	float dashForce = 80;
	bool attacking = false;
	bool grounded = false;
	bool dashing = false;
public:

	virtual void LoadAnimations() = 0;

	virtual void Start() override
	{
		Object& player = GetParent();


		FunctionParameters plC_Params = FunctionParameters();
		plC_Params.Add("Type", ColliderType::Dynamic);
		plC_Params.Add("Size", Vector2(0.8f, 1.3f));

		player.GetTransform().SetScale(3, 3);
		Collider& col = player.AddComponent<Collider>(plC_Params);

		col.SetFriction(5.0f);
		col.SetTriggerStartCallBack([&](Collider& other, FunctionParameters params) {
			this->TriggerEnter(other);
			});
	}

	void TriggerEnter(Collider& collider)
	{
		grounded = true;
	}

	virtual void Update() override;

};

class Lancer : public BaseCharacter
{
public:
	virtual void LoadAnimations() override;
	virtual void Start() override;
};
