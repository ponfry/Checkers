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
	void Set(CoordinateFloat* coordinate)
	{
		X = coordinate->X;
		Y = coordinate->Y;
	}
	bool CheckQuad(float x, float y)
	{
		if (x < (X + 0.125f) && x >(X - 0.125f)
			&& y < (Y + 0.125f) && y >(Y - 0.125f))
		{

			return true;
		}
		return false;
	}
	bool CheckQuad(CoordinateFloat* coordinate)
	{		
		return CheckQuad(coordinate->X, coordinate->Y);
	}
};

//__declspec(selectany) CoordinateFloat result;