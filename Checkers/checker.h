#pragma once
#include "Helper.h"
#include "MouseXY.h"

class Checker
{
public:
	void Draw(Coordinate);
	Checker(WindowSize*);
private:
	DrawTexture* draw;
	MouseXY mouse_xy;
};
