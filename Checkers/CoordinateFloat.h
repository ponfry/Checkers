#pragma once

struct CoordinateFloat
{
	float X;
	float Y;
	void Set(float x, float y)
	{
		X = x;
		Y = y;
	}
	void Set(CoordinateFloat coordinate)
	{
		X = coordinate.X;
		Y = coordinate.Y;
	}
};

//__declspec(selectany) CoordinateFloat result;