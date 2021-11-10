#include "Button.h"
#include <MEG_Input.h>
#include <iostream>
#include <MEG_Game.h>
#include "TestLevel.h"

void Button::Start()
{
}

void Button::Update()
{
	if (Clicked())
	{
		std::cout << "Presionado\n";
		Game::AddLevel(new TestLevel);
	}
}

void Button::Destroy()
{
}

bool Button::Clicked()
{
	if (Input::Mouse::KeyWasPressedThisFrame(1))
	{
		auto mouse_pos = Input::Mouse::MousePosition();
		auto pos = GetParent().GetTransformComponent().GetPosition() - (size/2);
		if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + size.x))
			if (mouse_pos.y > pos.y && mouse_pos.y < (pos.y + size.y))
				return true;
	}
	return false;
}
