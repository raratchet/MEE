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

	virtual void Start() override;

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
