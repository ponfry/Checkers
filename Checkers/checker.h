#pragma once
#include "CoordinateMouse.h"
#include "DrawTexture.h"
#include "CoordinatesFloat.h"

class Checker
{
public:
	void Draw(int);
private:
	void Init( int);
	CoordinateFloat coordinate_f;
	DrawTexture* draw;
	MyMouse mouse;
};
