#pragma once
#include "MEE_Components.h"
#include <iostream>

//Super Temporal
#include "MEE_Global.h"
#include "MEE_Object.h"


class TestBehaviour : public MEE::Behaviour
{
public:
	TestBehaviour(MEE::Object& parent) : MEE::Behaviour(parent) {}
	~TestBehaviour() { std::cout << "Se borra testbehaviour\n"; }

	virtual void start() override
	{

	}

	virtual void update() override
	{
		auto input = MEE_GLOBAL::application->getInputManager().lock();

		object.getTransform().setPosition(input->GetMouse());

	}
};