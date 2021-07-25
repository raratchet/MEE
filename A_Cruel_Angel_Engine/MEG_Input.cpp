#include "MEG_Input.h"
#include "MEG_Game.h"

bool Input::Keyboard::KeyWasPressedThisFrame(int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetKeyDown(key);
}

bool Input::Keyboard::KeyIsPressed(int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetKeyPressed(key);
}

bool Input::Keyboard::KeyUp(int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetKeyUp(key);
}

Vector2 Input::Mouse::MousePosition()
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetMouse();
}

bool Input::Mouse::KeyWasPressedThisFrame(int key)
{
	return false;
}

bool Input::Mouse::KeyIsPressed(int key)
{
	return false;
}

bool Input::Mouse::KeyUp(int key)
{
	return false;
}