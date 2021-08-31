#pragma once
#include <MEE_Components.h>
#include <MEG_Aliases.h>
#include <MEG_Input.h>
#include <MEE_Camera.h>
#include <MEG_Game.h>

class MEG_EXPORT Test : public Behaviour
{
public:

	virtual void Start() override
	{
		std::cout << "Iniciar Corutina\n";
		MEE::ResumableFunction func = test();
		Game::InitResumableFunction(&func);
	}

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

	MEE::ResumableFunction test()
	{
		std::cout << "Dentro de la Corutina\n";
		WaitForFrames(10);
		std::cout << "Termina la corutina\n";
	}
};

