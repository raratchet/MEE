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
	return input->GetMouse() / Game::GetMainApp()->GetRenderManager().lock()->GetPixelsPerUnit();
}

bool Input::Mouse::KeyWasPressedThisFrame(int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetMouseKeyDown(key);
}

bool Input::Mouse::KeyIsPressed(int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetMouseKeyPressed(key);
}

bool Input::Mouse::KeyUp(int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetMouseKeyUp(key);
}

bool Input::Controller::KeyWasPressedThisFrame(GamepadID id, int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetControllerKeyDown(id,key);
}

bool Input::Controller::KeyIsPressed(GamepadID id, int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetControllerKeyPressed(id,key);
}

bool Input::Controller::KeyUp(GamepadID id, int key)
{
	auto input = Game::GetMainApp()->GetInputManager().lock();
	return input->GetControllerKeyUp(id,key);
}
