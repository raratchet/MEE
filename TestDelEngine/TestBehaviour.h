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
		if (Input::Keyboard::KeyWasPressedThisFrame('a'))
			GetParent().GetTransform().Translate({ -7/60.0F,0 });
		if (Input::Keyboard::KeyWasPressedThisFrame('d'))
			GetParent().GetTransform().Translate({ 7 / 60.0F,0 });
		if (Input::Keyboard::KeyWasPressedThisFrame('w'))
			GetParent().GetTransform().Translate({ 0,-3 });
	}

};