#pragma once

struct CoordinateInt
{
	int X;
	int Y;

	CoordinateInt()
	{
		X = 0;
		Y = 0;
	}

	CoordinateInt(int x, int y)
	{
		X = x;
		Y = y;
	}

	void Set(int x, int y)
	{
		X = x;
		Y = y;
	}
};

__declspec(selectany)CoordinateInt coordinateMousePassiveMove;
__declspec(selectany)CoordinateInt coordinateMouseMove;
