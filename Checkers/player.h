#pragma once
#include "CoordinateFloat.h"
#include "CheckerWhite.h"
#include "CheckerBlack.h"

class Player
{
public:
	Player();
	void Draw();
	bool CheckCoordinatePassive();

	bool SetStateSelectChecker();
	void SetStateUnSelectChecker();
	
	bool SetWalkCoordinateSelectedChecker(CoordinateFloat*);
	bool SetBeatCoordinateSelectedChecker(CoordinateFloat*);

	bool CheckСonflictCoordinateCheckers(CoordinateFloat*);
	
	bool SetStateNotDrawChecker(CoordinateFloat*);
	void InitStartEndBeatCoordinate(CoordinateFloat*);
protected:
	virtual void InitChecker();
	void CheckCheckers();
	CoordinateFloat* checkCoordf;
	int indexSelected;
	Checker* checker, result;
};
