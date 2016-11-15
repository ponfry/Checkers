#pragma once
#include "checker.h"

class Player
{
public:
	Player();
	void Draw();
private:
	Checker* checker;
};
