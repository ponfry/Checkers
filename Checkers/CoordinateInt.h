#pragma once

struct CoordinateInt
{
	int X;
	int Y;
	void Set(int x, int y)
	{
		X = x;
		Y = y;
	}
};

__declspec(selectany)CoordinateInt coordinateMouseMoveI;
__declspec(selectany)CoordinateInt coordinateMousePassiveMove;