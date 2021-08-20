#include "TestLevel.h"
#include "TestBehaviour.h"


void TestLevel::Load()
{
	//Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Game::LoadAsset("Floor", "C:/Users/rarat/Pictures/floor.png");
	Game::LoadAsset("Player",  "C:/Users/rarat/Pictures/Assets-Test/knight_m_idle_anim_f0.png");
	Game::LoadAsset("Player1", "C:/Users/rarat/Pictures/Assets-Test/knight_m_idle_anim_f1.png");
	Game::LoadAsset("Player2", "C:/Users/rarat/Pictures/Assets-Test/knight_m_idle_anim_f2.png");
	Game::LoadAsset("Player3", "C:/Users/rarat/Pictures/Assets-Test/knight_m_idle_anim_f3.png");
	Game::LoadAsset("PlayerR",  "C:/Users/rarat/Pictures/Assets-Test/knight_m_run_anim_f0.png");
	Game::LoadAsset("Player2R", "C:/Users/rarat/Pictures/Assets-Test/knight_m_run_anim_f2.png");
	Game::LoadAsset("Player3R", "C:/Users/rarat/Pictures/Assets-Test/knight_m_run_anim_f3.png");
	Game::LoadAsset("Player1R", "C:/Users/rarat/Pictures/Assets-Test/knight_m_run_anim_f1.png");
	Sprite floorS = Sprite("Floor");
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& player = CreateGameObject("Player");
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransform().SetPosition(20, 20);


	player.AddComponent<TestBehaviour>();
}

void TestLevel::Unload()
{
}
