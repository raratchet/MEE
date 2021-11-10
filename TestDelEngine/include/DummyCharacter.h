#pragma once
#include "Characters.h"

class DummyCharacter : public BaseCharacter
{
public:
	virtual void Start() override;
	virtual void Update() override;

	void DanioRecibido(Collider& collider)
	{
		if (collider.GetParent().GetName() == "weaponHitBox")
			std::cout << "Danio recibido\n";
	}
private:
	virtual void LoadAnimations() override;
};
