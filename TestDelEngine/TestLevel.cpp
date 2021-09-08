#include "TestLevel.h"
#include "Characters.h"
#include "MEE_Camera.h"
#include "Test.h"
#include "DummyCharacter.h"
#include "MEE_UI.h"

void TestLevel::Load()
{
	//Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Game::LoadAsset("Floor", "C:/Users/rarat/Pictures/floor.png");
	Game::LoadAsset("POOO", "C:/Users/rarat/Pictures/player.png");

	Sprite floorS = Sprite("Floor");
	Sprite pooo = Sprite("POOO");
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& lancer = CreateGameObject("Lancer");
	GameObject& toxic = CreateGameObject("Toxic");
	GameObject& samurai = CreateGameObject("Samurai");
	GameObject& cowboy = CreateGameObject("Cowboy");
	GameObject& dummy = CreateGameObject("Dummy");
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransformComponent().SetPosition(20, 20);

	MEE::Camera& cam = this->GetMainCamera();
	MEE::UI_Image& ui = cam.AttachUIElement<MEE::UI_Image, MEE::Sprite&>("ui",pooo);
	ui.SetPosition(10, 10);

	dummy.AddComponent<DummyCharacter>();
	floor.AddComponent<Test>();
	lancer.AddComponent<Lancer>().debugController = true;
	toxic.AddComponent<Toxic>().debugController = true;
	samurai.AddComponent<Samurai>().debugController = true;
	cowboy.AddComponent<Cowboy>().debugController = true;

}

void TestLevel::Unload()
{
}
