#pragma once
#include "CheckerWhite.h"
#include "CoordinateFloat.h"

class Player
{
public:
	Player();
	void Draw();
	void SetStateSelectChecker();
	void SetStateUnSelectChecker();
	bool CheckCoordinatePassive();
	void SetCoordinateSelectedChecker(CoordinateFloat*);
private:
	void InitChecker();
	void CheckCheckers();
	CheckerWhite checker[12], result;
	CoordinateFloat* checkCoordf;
	int indexSelected;
};
