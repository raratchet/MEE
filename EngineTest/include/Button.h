#pragma once
#include <MEE_Components.h>
#include <MEG_Aliases.h>

class Button : public MEE::Behaviour
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void Destroy() override;
private:
	bool Clicked();
	Vector2 size = Vector2(10, 2);
};

