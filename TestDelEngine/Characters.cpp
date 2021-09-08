#include "Characters.h"
#include <iostream>
#include <cmath>

void BaseCharacter::Start()
{

	Object& player = GetParent();

	FunctionParameters plC_Params;
	plC_Params.Add("Type", ColliderType::Dynamic);
	plC_Params.Add("Size", Vector2(0.8f, 1.3f));

	player.GetTransformComponent().SetScale(3, 3);
	Collider& col = player.AddComponent<Collider>(plC_Params);
	myCollider = &col;

	col.SetFriction(5.0f);
	col.SetTriggerStartCallBack([&](Collider& other, FunctionParameters params) {
		this->TriggerEnter(other);
		});
	col.SetCollisionStartCallBack([&](Collider& other, FunctionParameters params) {
		this->CollisionEnter(other);
		});


	weaponHitBox = &GetParent().GetScene().CreateWorldObject("weaponHitBox");
	FunctionParameters wpC_Params;
	wpC_Params.Add("Type", ColliderType::Static);
	wpC_Params.Add("Size", Vector2(1.1f,0.3f));
	weaponHitBox->AddComponent<Collider>(wpC_Params).SetIsTrigger(true);
	weaponHitBox->GetTransformComponent().SetPosition(999, 999);
}

void BaseCharacter::TriggerEnter(Collider& collider)
{
	if (collider.GetParent().GetName() == "Floor")
		grounded = true;
}

void BaseCharacter::CollisionEnter(Collider& collider)
{
	if (collider.GetParent().GetName() != "Floor" && collider.GetParent().GetName() != "weaponHitBox")
	{
		auto pos1 = GetParent().GetTransformComponent().GetPosition();
		auto pos2 = collider.GetParent().GetTransformComponent().GetPosition();

		auto direction = (pos2 - pos1);

		if (direction.x > 0)
		{
			myCollider->ApplyLinearImpulse(Vector2(-5, -2), Vector2::Zero());
			collider.ApplyLinearImpulse(Vector2(5, -2), Vector2::Zero());
		}
		else if (direction.x < 0)
		{
			myCollider->ApplyLinearImpulse(Vector2(5, -2), Vector2::Zero());
			collider.ApplyLinearImpulse(Vector2(-5, -2), Vector2::Zero());
		}
		else
		{
			myCollider->ApplyLinearImpulse(Vector2(0, -2), Vector2::Zero());
			collider.ApplyLinearImpulse(Vector2(0, 2), Vector2::Zero());
		}
	}
}

void BaseCharacter::Update()
{
	GameObject& gObj = (GameObject&)GetParent();
	Collider& col = GetParent().GetComponent<Collider>();
	AnimationPlayer& player = GetParent().GetComponent<AnimationPlayer>();

	if (!dead)
	{
		auto pos = gObj.GetTransformComponent().GetPosition();

		if (pos.y > 45)
		{
			dead = true;
			std::cout << "Dead\n";
		}

		Animations(gObj, player);

		Move(gObj,col);

		Attack(gObj,col);

	}
	else
	{
		gObj.GetTransformComponent().SetPosition(777, 777);
		col.SetActive(false);
	}

}

void BaseCharacter::Attack(GameObject& gObj, Collider& col)
{
	if (Input::Controller::KeyWasPressedThisFrame(controllerID, 1) ||
		(debugController && Input::Keyboard::KeyWasPressedThisFrame('p')))
	{
		auto pos = gObj.GetTransformComponent().GetPosition();
		if (f_direction == FacingDirection::Right)
		{
			weaponHitBox->GetTransformComponent().SetPosition(pos.x + 3.0f, pos.y + 0.3f);
		}
		else if (f_direction == FacingDirection::Left)
		{
			weaponHitBox->GetTransformComponent().SetPosition(pos.x - 3.0f, pos.y + 0.3f);
		}
		attacking = true;
	}
}

void BaseCharacter::Move(GameObject& gObj, Collider& col)
{
	running = false;

	float xVel = std::abs(col.GetVelocity().x);


	if ((Input::Controller::KeyIsPressed(controllerID,13) && !attacking) ||
		(debugController && Input::Keyboard::KeyIsPressed('a') && !attacking))
	{
		if (xVel + runVelocity < maxVelocity)
		{
			col.SetVelocity(col.GetVelocity() + Vector2(-runVelocity, 0));
		}
		f_direction = FacingDirection::Left;
		gObj.SetHorizontalFlip(true);
		running = true;
	}
	if ((Input::Controller::KeyIsPressed(controllerID, 14) && !attacking) ||
		(debugController && Input::Keyboard::KeyIsPressed('d') && !attacking))
	{
		if (xVel + runVelocity < maxVelocity)
		{
			col.SetVelocity(col.GetVelocity() + Vector2(runVelocity, 0));
		}
		f_direction = FacingDirection::Right;
		gObj.SetHorizontalFlip(false);
		running = true;
	}


	if ((Input::Controller::KeyWasPressedThisFrame(controllerID, 0) && grounded) ||
		(debugController && Input::Keyboard::KeyWasPressedThisFrame('w') && grounded))
	{
		col.SetVelocity(col.GetVelocity() + Vector2(0, -jumpHeight));
		grounded = false;
	}

	if (Input::Controller::KeyWasPressedThisFrame(controllerID, 10) ||
		(debugController && Input::Keyboard::KeyWasPressedThisFrame('o')))
	{
		if (f_direction == FacingDirection::Right)
		{
			col.ApplyLinearImpulse(Vector2(dashForce, 0), Vector2::Zero());
			dashing = true;
		}
		else if (f_direction == FacingDirection::Left)
		{
			col.ApplyLinearImpulse(Vector2(-dashForce, 0), Vector2::Zero());
			dashing = true;
		}
	}
}

void BaseCharacter::Animations(GameObject& gObj, AnimationPlayer& player)
{
	Animation& attackAnim = player.GetAnimation("Attack");
	Animation& dashingAnim = player.GetAnimation("Dash");
	Animation& runAnim = player.GetAnimation("Run");

	if (attacking)
	{
		player.PlayAnimation("Attack");
		auto pos = gObj.GetTransformComponent().GetPosition();
		if (f_direction == FacingDirection::Right)
		{
			weaponHitBox->GetTransformComponent().SetPosition(pos.x + 3.0f, pos.y + 0.3f);
		}
		else if (f_direction == FacingDirection::Left)
		{
			weaponHitBox->GetTransformComponent().SetPosition(pos.x - 3.0f, pos.y + 0.3f);
		}
	}
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
		weaponHitBox->GetTransformComponent().SetPosition(999, 999);
		attacking = false;
	}
	if (dashingAnim.HasEnded())
	{
		dashing = false;
	}
}

Lancer::Lancer()
{
	controllerID = 0;
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

	GetParent().GetTransformComponent().SetPosition(5, 0);
}

Toxic::Toxic()
{
	controllerID = 1;
}

void Toxic::LoadAnimations()
{
	Object& player = GetParent();

	std::list<Sprite> idle;

	for (int i = 1; i <= 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/ToxicSword/Original/Hero/idle/idle0" + std::to_string(i) + ".png";
		Game::LoadAsset("ToxicSword" + std::to_string(i), path);
		Sprite sprite = Sprite("ToxicSword" + std::to_string(i));
		idle.push_back(sprite);
	}

	std::list<Sprite> run;

	for (int i = 1; i <= 8; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/ToxicSword/Original/Hero/run/run0" + std::to_string(i) + ".png";
		Game::LoadAsset("ToxicSwordRun" + std::to_string(i), path);
		Sprite sprite = Sprite("ToxicSwordRun" + std::to_string(i));
		run.push_back(sprite);
	}

	std::list<Sprite> attack;

	for (int i = 1; i <= 7; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/ToxicSword/Original/Hero/attack/attack0" + std::to_string(i) + ".png";
		Game::LoadAsset("ToxicSwordAttack" + std::to_string(i), path);
		Sprite sprite = Sprite("ToxicSwordAttack" + std::to_string(i));
		attack.push_back(sprite);
	}

	std::list<Sprite> jump;

	for (int i = 1; i <= 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/ToxicSword/Original/Hero/jump/jump0" + std::to_string(i) + ".png";
		Game::LoadAsset("ToxicSwordJump" + std::to_string(i), path);
		Sprite sprite = Sprite("ToxicSwordJump" + std::to_string(i));
		jump.push_back(sprite);
	}

	std::list<Sprite> dash;

	for (int i = 1; i <= 3; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/ToxicSword/Original/Hero/dash/dash0" + std::to_string(i) + ".png";
		Game::LoadAsset("ToxicSwordDash" + std::to_string(i), path);
		Sprite sprite = Sprite("ToxicSwordDash" + std::to_string(i));
		dash.push_back(sprite);
	}


	SpriteSheet idleSS = SpriteSheet(idle);
	SpriteSheet runSS = SpriteSheet(run);
	SpriteSheet attackSS = SpriteSheet(attack);
	SpriteSheet jumpSS = SpriteSheet(jump);
	SpriteSheet dashSS = SpriteSheet(dash);


	AnimationPlayer& animp = player.AddComponent<AnimationPlayer>();
	Animation idleAnim = Animation(idleSS);
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

void Toxic::Start()
{
	LoadAnimations();
	BaseCharacter::Start();
	GetParent().GetTransformComponent().SetPosition(10, 0);
}

Samurai::Samurai()
{
	controllerID = 2;
}

void Samurai::LoadAnimations()
{
	Object& player = GetParent();

	std::list<Sprite> idle;

	for (int i = 0; i < 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Samurai-Hero/Original/Hero/idle/idle0" + std::to_string(i) + ".png";
		Game::LoadAsset("Samurai" + std::to_string(i), path);
		Sprite sprite = Sprite("Samurai" + std::to_string(i));
		idle.push_back(sprite);
	}

	std::list<Sprite> run;

	for (int i = 0; i < 8; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Samurai-Hero/Original/Hero/run/run0" + std::to_string(i) + ".png";
		Game::LoadAsset("SamuraiRun" + std::to_string(i), path);
		Sprite sprite = Sprite("SamuraiRun" + std::to_string(i));
		run.push_back(sprite);
	}

	std::list<Sprite> attack;

	for (int i = 0; i < 8; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Samurai-Hero/Original/Hero/attack/attack0" + std::to_string(i) + ".png";
		Game::LoadAsset("SamuraiAttack" + std::to_string(i), path);
		Sprite sprite = Sprite("SamuraiAttack" + std::to_string(i));
		attack.push_back(sprite);
	}

	std::list<Sprite> jump;

	for (int i = 0; i < 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Samurai-Hero/Original/Hero/jump/jump0" + std::to_string(i) + ".png";
		Game::LoadAsset("SamuraiJump" + std::to_string(i), path);
		Sprite sprite = Sprite("SamuraiJump" + std::to_string(i));
		jump.push_back(sprite);
	}

	std::list<Sprite> dash;

	for (int i = 0; i <= 3; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Samurai-Hero/Original/Hero/dash/dash0" + std::to_string(i) + ".png";
		Game::LoadAsset("SamuraiDash" + std::to_string(i), path);
		Sprite sprite = Sprite("SamuraiDash" + std::to_string(i));
		dash.push_back(sprite);
	}


	SpriteSheet idleSS = SpriteSheet(idle);
	SpriteSheet runSS = SpriteSheet(run);
	SpriteSheet attackSS = SpriteSheet(attack);
	SpriteSheet jumpSS = SpriteSheet(jump);
	SpriteSheet dashSS = SpriteSheet(dash);


	AnimationPlayer& animp = player.AddComponent<AnimationPlayer>();
	Animation idleAnim = Animation(idleSS);
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

void Samurai::Start()
{
	LoadAnimations();
	BaseCharacter::Start();
	GetParent().GetTransformComponent().SetPosition(15, 0);
}

Cowboy::Cowboy()
{
	controllerID = 3;
}

void Cowboy::LoadAnimations()
{
	Object& player = GetParent();

	std::list<Sprite> idle;

	for (int i = 1; i <= 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Cowboy/Original/Hero/idle/idle0" + std::to_string(i) + ".png";
		Game::LoadAsset("Cowboy" + std::to_string(i), path);
		Sprite sprite = Sprite("Cowboy" + std::to_string(i));
		idle.push_back(sprite);
	}

	std::list<Sprite> run;

	for (int i = 1; i <= 8; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Cowboy/Original/Hero/run/run0" + std::to_string(i) + ".png";
		Game::LoadAsset("CowboyRun" + std::to_string(i), path);
		Sprite sprite = Sprite("CowboyRun" + std::to_string(i));
		run.push_back(sprite);
	}

	std::list<Sprite> attack;

	for (int i = 1; i <= 6; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Cowboy/Original/Hero/skill2/skill20" + std::to_string(i) + ".png";
		Game::LoadAsset("CowboyAttack" + std::to_string(i), path);
		Sprite sprite = Sprite("CowboyAttack" + std::to_string(i));
		attack.push_back(sprite);
	}

	std::list<Sprite> jump;

	for (int i = 1; i <= 4; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Cowboy/Original/Hero/jump/jump0" + std::to_string(i) + ".png";
		Game::LoadAsset("CowboyJump" + std::to_string(i), path);
		Sprite sprite = Sprite("CowboyJump" + std::to_string(i));
		jump.push_back(sprite);
	}

	std::list<Sprite> dash;

	for (int i = 1; i <= 1; i++)
	{
		std::string path = "C:/Users/rarat/Pictures/Cowboy/Original/Hero/dash/dash0" + std::to_string(i) + ".png";
		Game::LoadAsset("CowboyDash" + std::to_string(i), path);
		Sprite sprite = Sprite("CowboyDash" + std::to_string(i));
		dash.push_back(sprite);
	}


	SpriteSheet idleSS = SpriteSheet(idle);
	SpriteSheet runSS = SpriteSheet(run);
	SpriteSheet attackSS = SpriteSheet(attack);
	SpriteSheet jumpSS = SpriteSheet(jump);
	SpriteSheet dashSS = SpriteSheet(dash);


	AnimationPlayer& animp = player.AddComponent<AnimationPlayer>();
	Animation idleAnim = Animation(idleSS);
	Animation runAnim = Animation(runSS);
	Animation attackAnim = Animation(attackSS);
	attackAnim.SetShouldLoop(false);
	Animation jumpAnim = Animation(jumpSS);
	jumpAnim.SetShouldLoop(false);
	Animation dashAnim = Animation(dashSS);
	dashAnim.SetShouldLoop(false);
	dashAnim.SetFrameDuration(0, 4);

	animp.SetAnimationFrameDuration(10);
	animp.AddAnimation("Idle", idleAnim);
	animp.AddAnimation("Run", runAnim);
	animp.AddAnimation("Attack", attackAnim);
	animp.AddAnimation("Jump", jumpAnim);
	animp.AddAnimation("Dash", dashAnim);
}

void Cowboy::Start()
{
	LoadAnimations();
	BaseCharacter::Start();
	GetParent().GetTransformComponent().SetPosition(20, 0);
}
