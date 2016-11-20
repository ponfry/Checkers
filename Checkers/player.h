#pragma once
#include "CheckerWhite.h"

class Player
{
public:
	Player();
	void Draw();
	void ControlCoordinate();
	bool CheckCoordinatePassive();
private:
	void InitChecker();
	CheckerWhite checker[12];
	CoordinateFloat* checkCoordf;
};
