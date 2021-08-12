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

		if (Input::Keyboard::KeyWasPressedThisFrame('a'))
			col.ApplyLinearImpulse({ -1,0 }, Vector2::Zero());
		if (Input::Keyboard::KeyWasPressedThisFrame('d'))
			col.ApplyLinearImpulse({ 1,0 }, Vector2::Zero());
		if (Input::Keyboard::KeyWasPressedThisFrame('w'))
			col.ApplyLinearImpulse({ 0,-3 }, Vector2::Zero());
	}

};