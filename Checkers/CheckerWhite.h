#pragma once
#include "checker.h"
class CheckerWhite :
	public Checker
{
public:
	CheckerWhite();	
	void SetCoordinate(int, int) override;
	void SetCoordinate(float, float) override;
protected:	
	void CheckWalkCoordinate(CoordinateInt*) override;
	void CheckBeatCoordinate(CoordinateInt*) override;

	
};

