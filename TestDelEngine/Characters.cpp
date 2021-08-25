#include "Characters.h"
#include <iostream>
#include <cmath>

void BaseCharacter::Update()
{
	Collider& col = GetParent().GetComponent<Collider>();
	AnimationPlayer& player = GetParent().GetComponent<AnimationPlayer>();
	GameObject& gObj = (GameObject&)GetParent();

	Animation& attackAnim = player.GetAnimation("Attack");
	Animation& dashingAnim = player.GetAnimation("Dash");
	Animation& runAnim = player.GetAnimation("Run");


	if (attacking)
		player.PlayAnimation("Attack");
	else if (dashing)
		player.PlayAnimation("Dash");
	else if (!grounded)
		player.PlayAnimation("Jump");
	else if (running)
		player.PlayAnimation("Run");
	else
		player.PlayAnimation("Idle");

	if (attackAnim.HasEnded())
	{
		attacking = false;
	}
	if (dashingAnim.HasEnded())
	{
		dashing = false;
	}

	running = false;

	float xVel = std::abs(col.GetVelocity().x);


	if (Input::Keyboard::KeyIsPressed('a') && !attacking)
	{
		if (xVel + runVelocity < maxVelocity)
		{
			col.SetVelocity(col.GetVelocity() + Vector2(-runVelocity, 0));
		}
		gObj.SetHorizontalFlip(true);
		running = true;
	}
	if (Input::Keyboard::KeyIsPressed('d') && !attacking)
	{
		if (xVel + runVelocity < maxVelocity)
		{
			col.SetVelocity(col.GetVelocity() + Vector2(runVelocity, 0));
		}
		gObj.SetHorizontalFlip(false);
		running = true;
	}

	if (Input::Keyboard::KeyWasPressedThisFrame('w') && grounded)
	{
		col.SetVelocity(col.GetVelocity() + Vector2(0, -jumpHeight));
		grounded = false;
	}

	if (Input::Keyboard::KeyWasPressedThisFrame('p'))
	{
		attacking = true;
	}

	if (Input::Keyboard::KeyWasPressedThisFrame('o'))
	{
		if (Input::Keyboard::KeyIsPressed('d'))
		{
			col.ApplyLinearImpulse(Vector2(dashForce,0), Vector2::Zero());
			dashing = true;
		}
		else if (Input::Keyboard::KeyIsPressed('a'))
		{
			col.ApplyLinearImpulse(Vector2(-dashForce, 0), Vector2::Zero());
			dashing = true;
		}
	}
}

void Lancer::LoadAnimations()
{

	Object& player = GetParent();

	std::list<Sprite> idle;

	for (int i = 1; i <= 14; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Lancer-Hero/Original/Hero/idle/idle0" + std::to_string(i) + ".png";
		Game::LoadAsset("Lancer" + std::to_string(i), path);
		Sprite sprite = Sprite("Lancer" + std::to_string(i));
		idle.push_back(sprite);
	}

	std::list<Sprite> run;

	for (int i = 1; i <= 8; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Lancer-Hero/Original/Hero/run/run0" + std::to_string(i) + ".png";
		Game::LoadAsset("LancerRun" + std::to_string(i), path);
		Sprite sprite = Sprite("LancerRun" + std::to_string(i));
		run.push_back(sprite);
	}

	std::list<Sprite> attack;

	for (int i = 1; i <= 6; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Lancer-Hero/Original/Hero/attack/attack0" + std::to_string(i) + ".png";
		Game::LoadAsset("LancerAttack" + std::to_string(i), path);
		Sprite sprite = Sprite("LancerAttack" + std::to_string(i));
		attack.push_back(sprite);
	}

	std::list<Sprite> jump;

	for (int i = 1; i <= 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Lancer-Hero/Original/Hero/jump/jump0" + std::to_string(i) + ".png";
		Game::LoadAsset("LancerJump" + std::to_string(i), path);
		Sprite sprite = Sprite("LancerJump" + std::to_string(i));
		jump.push_back(sprite);
	}

	std::list<Sprite> dash;

	for (int i = 1; i <= 3; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Lancer-Hero/Original/Hero/dash/dash0" + std::to_string(i) + ".png";
		Game::LoadAsset("LancerDash" + std::to_string(i), path);
		Sprite sprite = Sprite("LancerDash" + std::to_string(i));
		dash.push_back(sprite);
	}


	SpriteSheet idleSS = SpriteSheet(idle);
	SpriteSheet runSS = SpriteSheet(run);
	SpriteSheet attackSS = SpriteSheet(attack);
	SpriteSheet jumpSS = SpriteSheet(jump);
	SpriteSheet dashSS = SpriteSheet(dash);


	AnimationPlayer& animp = player.AddComponent<AnimationPlayer>();
	Animation idleAnim = Animation(idleSS);
	idleAnim.SetFrameDuration(0, 7);
	Animation runAnim = Animation(runSS);
	Animation attackAnim = Animation(attackSS);
	attackAnim.SetShouldLoop(false);
	Animation jumpAnim = Animation(jumpSS);
	jumpAnim.SetShouldLoop(false);
	Animation dashAnim = Animation(dashSS);
	dashAnim.SetShouldLoop(false);

	animp.SetAnimationFrameDuration(10);
	animp.AddAnimation("Idle", idleAnim);
	animp.AddAnimation("Run", runAnim);
	animp.AddAnimation("Attack", attackAnim);
	animp.AddAnimation("Jump", jumpAnim);
	animp.AddAnimation("Dash", dashAnim);
}

void Lancer::Start()
{
	LoadAnimations();
	BaseCharacter::Start();
}
