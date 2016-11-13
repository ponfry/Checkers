#pragma once
#include "Helper.h"
#include "MouseXY.h"

class Checker
{
public:
	void Draw(float, float);
	Checker(WindowSize*, int color);
private:
	DrawTexture* draw;
	MouseXY mouse_xy;
};
