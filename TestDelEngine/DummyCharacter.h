#pragma once
#include "Characters.h"

class DummyCharacter : public BaseCharacter
{
public:
	virtual void Start() override;
	virtual void Update() override;
private:
	virtual void LoadAnimations() override;
};
