#include "DummyCharacter.h"

void DummyCharacter::Start()
{
	LoadAnimations();
	BaseCharacter::Start();
	myCollider->SetTriggerStartCallBack([&](Collider& other, FunctionParameters params) {
		this->DanioRecibido(other);
		});
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

	obj.GetTransformComponent().SetPosition(Vector2(25,0));

}
