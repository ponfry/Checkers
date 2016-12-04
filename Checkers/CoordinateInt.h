#pragma once
#include "WindowSize.h"

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

	bool CheckRectangle(int x, int y)
	{
		int Xi = window_size.Weigth / 13;
		int Yi = window_size.Heigth / 32.5 + 1;

		if (x < (X + Xi) && x >(X - Xi)
			&& y < (Y + Yi) && y >(Y - Yi))
		{
			return true;
		}
		return false;
	}

	bool CheckRectangle(CoordinateInt* coordinate)
	{
		return CheckRectangle(coordinate->X, coordinate->Y);
	}
};

__declspec(selectany)CoordinateInt coordinateMousePassiveMove;
__declspec(selectany)CoordinateInt coordinateMouseMove;
