#include "TestLevel.h"
#include "TestBehaviour.h"


void TestLevel::Load()
{
	//Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Game::LoadAsset("Floor", "C:/Users/rarat/Pictures/floor.png");
	Game::LoadAsset("Player", "C:/Users/rarat/Pictures/player.png");
	Sprite floorS = Sprite("Floor", 0, 0, 820,25);
	Sprite playerS = Sprite("Player", 0, 0, 20, 20);
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& player = CreateGameObject("Player",playerS);
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransform().SetPosition(0, 600);
	Collider& pp = player.AddComponent<Collider>();
	pp.SetType(ColliderType::Dynamic);
	player.GetTransform().SetPosition(300, 300);
	player.AddComponent<TestBehaviour>();
}

void TestLevel::Unload()
{
}
