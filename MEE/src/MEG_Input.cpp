#include "MEG_Input.h"
#include "MEG_Game.h"

bool Input::Keyboard::KeyWasPressedThisFrame(int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetKeyDown(key);
}

bool Input::Keyboard::KeyIsPressed(int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetKeyPressed(key);
}

bool Input::Keyboard::KeyUp(int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetKeyUp(key);
}

Vector2 Input::Mouse::MousePosition()
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetMouse() / Game::GetMainApp()->GetRenderManager()->GetPixelsPerUnit();
}

bool Input::Mouse::KeyWasPressedThisFrame(int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetMouseKeyDown(key);
}

bool Input::Mouse::KeyIsPressed(int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetMouseKeyPressed(key);
}

bool Input::Mouse::KeyUp(int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetMouseKeyUp(key);
}

bool Input::Controller::KeyWasPressedThisFrame(GamepadID id, int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetControllerKeyDown(id,key);
}

bool Input::Controller::KeyIsPressed(GamepadID id, int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetControllerKeyPressed(id,key);
}

bool Input::Controller::KeyUp(GamepadID id, int key)
{
	auto input = Game::GetMainApp()->GetInputManager();
	return input->GetControllerKeyUp(id,key);
}
