#pragma once
#include "checker.h"

class CheckerBlack :public Checker
{
public:
	CheckerBlack();
	void SetCoordinate(int, int) override;
	void SetCoordinate(float, float) override;
protected:
	void Init() override;
	void CheckWalkCoordinate(CoordinateInt*) override;
	void CheckBeatCoordinate(CoordinateInt*)  override;

	
};
