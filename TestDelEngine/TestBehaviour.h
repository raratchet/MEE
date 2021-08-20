#pragma once
#include "MEG_Game.h"
#include "MEG_Input.h"
#include <iostream>
#include <cmath>

class TestBehaviour : public Behaviour
{
private:
	bool running = false;
	float maxVelocity = 6;
	float runVel = 1;

public:
	virtual void Start() override
	{
		Object& player = GetParent();

		Sprite playerS = Sprite("Player");
		Sprite playerS1 = Sprite("Player1");
		Sprite playerS2 = Sprite("Player2");
		Sprite playerS3 = Sprite("Player3");
		Sprite playerSR = Sprite("PlayerR");
		Sprite playerS1R = Sprite("Player1R");
		Sprite playerS2R = Sprite("Player2R");
		Sprite playerS3R = Sprite("Player3R");
		SpriteSheet playerSS = SpriteSheet({ playerS,playerS1,playerS2,playerS3 });
		SpriteSheet playerSSRun = SpriteSheet({ playerSR,playerS1R,playerS2R,playerS3R });
		//pp.SetType(ColliderType::Dynamic);
		player.GetTransform().SetPosition(20, 10);
		AnimationPlayer& animp = player.AddComponent<AnimationPlayer>();
		Animation idle = Animation(playerSS);
		Animation run = Animation(playerSSRun);
		animp.SetAnimationFrameDuaration(10);
		animp.AddAnimation("Idle", idle);
		animp.AddAnimation("Run", run);

		FunctionParameters plC_Params = FunctionParameters();
		plC_Params.Add("Type", ColliderType::Dynamic);
		//plC_Params.Add("Size", Vector2(0.8f, 1.3f));

		player.GetTransform().SetScale(3, 3);
		Collider& col = player.AddComponent<Collider>(plC_Params);

		col.SetFriction(5.0f);
		col.SetTriggerStartCallBack([&](Collider& other) {
			this->TriggerEnter(other);
			});
	}

	void TriggerEnter(Collider& collider)
	{
		std::cout << "AMAM\n";
	}

	virtual void Update() override
	{
		Collider& col = GetParent().GetComponent<Collider>();
		AnimationPlayer& player = GetParent().GetComponent<AnimationPlayer>();
		Object& obj = GetParent();
		GameObject& gObj = (GameObject&) obj;

		if (!running)
			player.PlayAnimation("Idle");
		else
			player.PlayAnimation("Run");

		running = false;
		//col.SetVelocity(Vector2::Zero());

		float xVel = std::abs(col.GetVelocity().x);


		if (Input::Keyboard::KeyIsPressed('a'))
		{
			//obj.GetTransform().Translate(Vector2(-6, 0) * Game::GetDeltaTime());
			//col.ApplyLinearImpulse(Vector2(-1, 0) * Game::GetDeltaTime(), Vector2::Zero());
			if (xVel + runVel < maxVelocity)
			{
				col.SetVelocity(col.GetVelocity() + Vector2(-runVel,0));
			}
			gObj.SetHorizontalFlip(true);
			running = true;
		}
		if (Input::Keyboard::KeyIsPressed('d'))
		{
			//obj.GetTransform().Translate(Vector2(6, 0) * Game::GetDeltaTime());
			//col.ApplyLinearImpulse(Vector2(1,0) * Game::GetDeltaTime(), Vector2::Zero());
			if (xVel + runVel < maxVelocity)
			{
				col.SetVelocity(col.GetVelocity() + Vector2(runVel, 0));
			}
			gObj.SetHorizontalFlip(false);
			running = true;
		}
		if (Input::Keyboard::KeyWasPressedThisFrame('w'))
		{
			//col.ApplyLinearImpulse({ 0,-12 }, Vector2::Zero());
			col.SetVelocity(col.GetVelocity() + Vector2(0, -6));
		}


		if (Input::Keyboard::KeyWasPressedThisFrame('p'))
		{
			std::cout << "Se oprime p \n";
			Input::Keyboard::KeyWasPressedThisFrame('p');
		}
		if (Input::Keyboard::KeyIsPressed('l'))
			std::cout << "Se deja oprimido l \n";
	}

};