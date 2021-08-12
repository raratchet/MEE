#include "TestLevel.h"
#include "TestBehaviour.h"


void TestLevel::Load()
{
	//Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Game::LoadAsset("Floor", "C:/Users/rarat/Pictures/floor.png");
	Game::LoadAsset("Player", "C:/Users/rarat/Pictures/player.png");
	Sprite floorS = Sprite("Floor", 0, 0, 820,20);
	Sprite playerS = Sprite("Player", 0, 0, 20, 20);
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& player = CreateGameObject("Player",playerS);
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransform().SetPosition(20, 20);

	FunctionParameters plC_Params = FunctionParameters();
	plC_Params.Add("Type", ColliderType::Dynamic);

	Collider& pp = player.AddComponent<Collider>(plC_Params);
	pp.SetType(ColliderType::Dynamic);
	player.GetTransform().SetPosition(20, 10);
	player.AddComponent<TestBehaviour>();
}

void TestLevel::Unload()
{
}
