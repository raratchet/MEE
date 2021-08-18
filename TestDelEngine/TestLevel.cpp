#include "TestLevel.h"
#include "TestBehaviour.h"


void TestLevel::Load()
{
	//Game::LoadAsset("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Game::LoadAsset("Floor", "C:/Users/rarat/Pictures/floor.png");
	Game::LoadAsset("Player", "C:/Users/rarat/Pictures/player.png");
	Game::LoadAsset("Player1", "C:/Users/rarat/Pictures/player1.png");
	Game::LoadAsset("Player2", "C:/Users/rarat/Pictures/player2.png");
	Game::LoadAsset("Player3", "C:/Users/rarat/Pictures/player3.png");
	Sprite floorS = Sprite("Floor", 0, 0, 820,20);
	Sprite playerS = Sprite("Player", 0, 0, 20, 20);
	Sprite playerS1 = Sprite("Player1", 0, 0, 20, 20);
	Sprite playerS2 = Sprite("Player2", 0, 0, 20, 20);
	Sprite playerS3 = Sprite("Player3", 0, 0, 20, 20);
	SpriteSheet playerSS = SpriteSheet({playerS,playerS1,playerS2,playerS3});
	GameObject& floor = CreateGameObject("Floor",floorS);
	GameObject& player = CreateGameObject("Player",playerS);
	Collider fCollider = floor.AddComponent<Collider>();
	floor.GetTransform().SetPosition(20, 20);

	FunctionParameters plC_Params = FunctionParameters();
	plC_Params.Add("Type", ColliderType::Dynamic);

	Collider& pp = player.AddComponent<Collider>(plC_Params);
	//pp.SetType(ColliderType::Dynamic);
	player.GetTransform().SetPosition(20, 10);
	AnimationPlayer& animp = player.AddComponent<AnimationPlayer>();
	Animation anim = Animation(playerSS);
	animp.SetAnimationFrameDuaration(180);
	animp.AddAnimation("Anim", anim);
	player.AddComponent<TestBehaviour>();
}

void TestLevel::Unload()
{
}
