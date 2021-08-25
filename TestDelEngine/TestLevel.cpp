#include "TestLevel.h"
#include "Characters.h"
#include "MEE_Camera.h"
#include "Test.h"

void TestLevel::Load()
{
	//Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Game::LoadAsset("Floor", "C:/Users/rarat/Pictures/floor.png");

	Sprite floorS = Sprite("Floor");
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& player = CreateGameObject("Player");
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransform().SetPosition(20, 20);


	floor.AddComponent<Test>();
	player.AddComponent<Lancer>();

}

void TestLevel::Unload()
{
}
