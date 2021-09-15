#include "MainMenu.h"
#include "Button.h"

void MainMenu::Load()
{
	Game::LoadAsset("PlayButton", "./play.png");
	Sprite button("PlayButton");

	GameObject& buttonObj = CreateGameObject("Button", button);

	buttonObj.AddComponent<Button>();
	buttonObj.GetTransformComponent().SetPosition(20, 20);
}

void MainMenu::Unload()
{
}
