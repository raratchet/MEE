#pragma once
#include "MEE_Scene.h"


class TestLevel : public MEE::Scene
{
	// Heredado v�a AppState
	virtual void load() override;
	virtual void unload() override;
};

