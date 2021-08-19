#pragma once
#include "MEG_Game.h"
#include "MEG_Input.h"
#include <iostream>


class TestBehaviour : public Behaviour
{

public:
	virtual void Start() override
	{

	}

	virtual void Update() override
	{
		Collider& col = GetParent().GetComponent<Collider>();
		Object& obj = GetParent();

		if (Input::Keyboard::KeyWasPressedThisFrame('a'))
			obj.GetTransform().Translate(Vector2(-6, 0) * Game::GetDeltaTime());
			//col.ApplyLinearImpulse(Vector2(-1, 0) * Game::GetDeltaTime(), Vector2::Zero());
		if (Input::Keyboard::KeyWasPressedThisFrame('d'))
			obj.GetTransform().Translate(Vector2(6, 0) * Game::GetDeltaTime());
			//col.ApplyLinearImpulse(Vector2(1,0) * Game::GetDeltaTime(), Vector2::Zero());
		if (Input::Keyboard::KeyWasPressedThisFrame('w'))
			col.ApplyLinearImpulse({ 0,-12 }, Vector2::Zero());

		if (Input::Keyboard::KeyWasPressedThisFrame('p'))
			std::cout << "Se oprime p \n";
		if (Input::Keyboard::KeyIsPressed('l'))
			std::cout << "Se deja oprimido l \n";
	}

};