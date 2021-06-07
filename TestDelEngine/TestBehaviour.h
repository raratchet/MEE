#pragma once
#include "MEG_Game.h"
#include <iostream>


class TestBehaviour : public Behaviour
{

public:
	virtual void Start() override
	{

	}

	virtual void Update() override
	{
		//auto input = MEE_GLOBAL::application->GetInputManager().lock();

		//Obj().GetTransform().SetPosition(input->GetMouse());

	}

};