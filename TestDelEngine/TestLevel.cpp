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
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& lancer = CreateGameObject("Lancer");
	GameObject& toxic = CreateGameObject("Toxic");
	GameObject& samurai = CreateGameObject("Samurai");
	GameObject& cowboy = CreateGameObject("Cowboy");
	GameObject& dummy = CreateGameObject("Dummy");
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransformComponent().SetPosition(20, 20);

	MEE::Camera& cam = this->GetMainCamera();
	//MEE::UI_Image& ui = cam.AttachUIElement<MEE::UI_Image, MEE::Sprite&>("ui",pooo);
	//ui.SetPosition(10, 10);

	dummy.AddComponent<DummyCharacter>();
	floor.AddComponent<Test>();
	lancer.AddComponent<Lancer>().debugController = false;
	toxic.AddComponent<Toxic>().debugController = false;
	samurai.AddComponent<Samurai>().debugController = true;
	cowboy.AddComponent<Cowboy>().debugController = true;

}

void TestLevel::Unload()
{
}
