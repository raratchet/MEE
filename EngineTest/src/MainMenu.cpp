#include "MainMenu.h"
#include "Button.h"

void MainMenu::Load()
{
	Game::LoadAsset("PlayButton", "./play.png");
	Game::LoadAsset("Title", "./PF.png");
	Sprite button("PlayButton");
	Sprite title("Title");

	auto buttonObj = CreateGameObject("Button", button);
	auto titileObj = CreateGameObject("Title", title);

	buttonObj->AddComponent<Button>();
	buttonObj->GetTransformComponent().SetPosition(20, 20);
	titileObj->GetTransformComponent().SetPosition(20, 10);
}

void MainMenu::Unload()
{
}
