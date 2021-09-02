#include "DummyCharacter.h"

void DummyCharacter::Start()
{
	LoadAnimations();
	BaseCharacter::Start();
}

void DummyCharacter::Update()
{
}

void DummyCharacter::LoadAnimations()
{
	GameObject& obj = (GameObject&)GetParent();

	Game::LoadAsset("Dummy", "C:/Users/rarat/Pictures/Assets-Test/knight_m_idle_anim_f0.png");
	Sprite sprite = Sprite("Dummy");
	obj.SetSprite(sprite);

	obj.GetTransform().SetPosition(Vector2(18,4));

}
