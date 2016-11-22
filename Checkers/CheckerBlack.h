#pragma once
#include "checker.h"

class CheckerBlack :public Checker
{
public:
	CheckerBlack();
	bool CheckWalkCoordinate(CoordinateFloat*) override;
protected:
	void Init() override;
};
