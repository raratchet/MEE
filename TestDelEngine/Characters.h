#pragma once
#include "MEG_Game.h"
#include "MEG_Input.h"
#include "WinScreen.h"

enum class FacingDirection
{
	Right = 0 , Left = 1
};

class BaseCharacter : public Behaviour
{
protected:
	bool running = false;
	float maxVelocity = 6;
	float runVelocity = 1;
	float jumpHeight = 11;
	float dashForce = 80;
	bool attacking = false;
	bool grounded = false;
	bool dashing = false;
	bool dead = false;
	int controllerID = 0;
	int hp = 3;
	int deadCounter = 0;
	int deadCounterCond = 180;
	FacingDirection f_direction = FacingDirection::Right;
	Collider* myCollider;
	WorldObject* weaponHitBox;
	WinScreen* winScreen;
public:
	static std::list<BaseCharacter*> alive;
	bool debugController = false;
	virtual void LoadAnimations() = 0;

	virtual void Start() override;

	void TriggerEnter(Collider& collider);

	void CollisionEnter(Collider& collider);

	void TakeDamge();

	virtual void Update() override;

	void Move(GameObject& gObj, Collider& col);
	void Attack(GameObject& gObj, Collider& col);
	void Animations(GameObject& gObj, AnimationPlayer& player);

};

class Lancer : public BaseCharacter
{
public:
	Lancer();
	virtual void LoadAnimations() override;
	virtual void Start() override;
};

class Toxic : public BaseCharacter
{
public:
	Toxic();
	virtual void LoadAnimations() override;
	virtual void Start() override;
};

class Samurai : public BaseCharacter
{
public:
	Samurai();
	virtual void LoadAnimations() override;
	virtual void Start() override;
};

class Cowboy : public BaseCharacter
{
public:
	Cowboy();
	virtual void LoadAnimations() override;
	virtual void Start() override;
};
