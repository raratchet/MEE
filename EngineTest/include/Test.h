#pragma once
#include <MEE_Components.h>
#include <MEG_Aliases.h>
#include <MEG_Input.h>
#include <MEE_Camera.h>

class Test : public Behaviour
{
	virtual void Update() override
	{
		MEE::Camera& camera = GetParent().GetScene().GetMainCamera();

		if (Input::Keyboard::KeyWasPressedThisFrame('n'))
		{
			Vector2 pos = camera.GetPosition();
			camera.SetPosition(pos + Vector2(-1, 0));
		}

		if (Input::Keyboard::KeyWasPressedThisFrame('m'))
		{
			Vector2 pos = camera.GetPosition();
			camera.SetPosition(pos + Vector2(1, 0));
		}
	}
};

