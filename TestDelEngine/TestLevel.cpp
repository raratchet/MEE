#include "TestLevel.h"
#include "TestBehaviour.h"


void TestLevel::Load()
{
	Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Sprite testS = Sprite("Regu", 0, 0, 2000, 2000);
	GameObject& regu = CreateGameObject("REGU",testS);
	regu.AddComponent<Collider>();
	regu.AddComponent<TestBehaviour>();
}

void TestLevel::Unload()
{
}
