#include "TestLevel.h"
#include "Characters.h"
#include "MEE_Camera.h"
#include "Test.h"
#include "DummyCharacter.h"
#include "MEE_UI.h"

void TestLevel::Load()
{
	Game::LoadAsset("Floor", "./floor.png");

	Sprite floorS = Sprite("Floor");
	auto floor = CreateGameObject("Floor",floorS);
	auto lancer = CreateGameObject("Lancer");
	auto toxic = CreateGameObject("Toxic");
	auto samurai = CreateGameObject("Samurai");
	auto cowboy = CreateGameObject("Cowboy");
	//auto dummy = CreateGameObject("Dummy");
	Collider fCollider = floor->AddComponent<Collider>();
	floor->GetTransformComponent().SetPosition(20, 20);

	auto cam = this->GetMainCamera();
	//MEE::UI_Image& ui = cam.AttachUIElement<MEE::UI_Image, MEE::Sprite&>("ui",pooo);
	//ui.SetPosition(10, 10);

	//dummy.AddComponent<DummyCharacter>();
	floor->AddComponent<Test>();
	lancer->AddComponent<Lancer>().debugController = false;
	toxic->AddComponent<Toxic>().debugController = false;
	samurai->AddComponent<Samurai>().debugController = true;
	cowboy->AddComponent<Cowboy>().debugController = true;

}

void TestLevel::Unload()
{
}
