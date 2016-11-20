#pragma once
#include "CheckerWhite.h"

class Player
{
public:
	Player();
	void Draw();
	void SetStateSelectChecker();
	bool CheckCoordinatePassive();
	void Setc();
private:
	void InitChecker();
	void CheckCheckers();
	CheckerWhite checker[12];
	CoordinateFloat* checkCoordf;
	int index;
};
