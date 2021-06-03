#pragma once
#include "MEE_Scene.h"


class TestLevel : public MEE::Scene
{
	// Heredado vía AppState
	virtual void Load() override;
	virtual void Unload() override;
};

