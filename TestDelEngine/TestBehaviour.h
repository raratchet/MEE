#pragma once
#include "MEE_Components.h"
#include <iostream>

//Super Temporal
#include "MEE_Global.h"
#include "MEE_Object.h"


class TestBehaviour : public MEE::Behaviour
{

public:
	virtual void Start() override
	{

	}

	virtual void Update() override
	{
		auto input = MEE_GLOBAL::application->GetInputManager().lock();

		Obj().GetTransform().SetPosition(input->GetMouse());

	}

	virtual void Destroy() override
	{

	}
};