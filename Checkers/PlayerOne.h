#pragma once
#include "player.h"
#include "CheckerWhite.h"

class PlayerOne :
	public Player
{
public:
	PlayerOne();
	void InitChecker() override;	
};

