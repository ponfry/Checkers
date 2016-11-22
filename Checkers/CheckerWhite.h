#pragma once
#include "checker.h"
class CheckerWhite :
	public Checker
{
public:
	CheckerWhite();	
	 bool CheckWalkCoordinate(CoordinateFloat*) override;
protected:	
	void Init() override;
};

