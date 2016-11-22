#pragma once
#include "player.h"
#include "CheckerBlack.h"

class PlayerTwo :
	public Player
{
public:
	PlayerTwo();
	void InitChecker() override;
};

