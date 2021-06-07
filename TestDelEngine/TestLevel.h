#pragma once
#include "MEG_Game.h"


class TestLevel : public Level
{
	// Heredado vía AppState
	virtual void Load() override;
	virtual void Unload() override;
};

