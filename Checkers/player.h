#pragma once
#include "CoordinateFloat.h"
#include "CheckerWhite.h"
#include "CheckerBlack.h"
#include "FlagsPlayer.h"

class Player
{
public:
	Player();
	void Draw();
	bool CheckCoordinatePassive();

	bool SetStateSelectChecker();
	void SetStateUnSelectChecker();	
	bool SetStateNotDrawChecker();	

	void ControlMovesCheckers();
	bool SetNewCoordinateChecker(CoordinateFloat*);

	bool CheckСonflictCoordinateCheckers(CoordinateFloat*);
	
protected:
	virtual void InitChecker();
	void CheckCheckers();
	FlagsPlayer* flags;
	CoordinateFloat* checkCoordf;
	int indexSelected, CountCheckers;
	Checker *checker;
};
