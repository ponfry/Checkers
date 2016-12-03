#pragma once

struct CoordinateFloat
{
	float X;
	float Y;
	CoordinateFloat()
	{
		X = 0;
		Y = 0;
	}

	CoordinateFloat(float x, float y)
	{
		X = x;
		Y = y;
	}

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

	bool CheckRectangle(float x, float y )
	{
		if (x < (X + 0.15f) && x >(X - 0.15f)
			&& y < (Y + 0.0615f) && y >(Y - 0.0615f))
		{
			return true;
		}
		return false;
	}

	bool CheckRectangle(CoordinateFloat* coordinate)
	{
		return CheckRectangle(coordinate->X, coordinate->Y);
	}
	bool operator ==(CoordinateFloat* coordinateone)
	{
		if(coordinateone->X == X && coordinateone->Y == Y)
		{
			return true;
		}
		return false;
	}
};

__declspec(selectany) CoordinateFloat coordinateNotDrawChecker;

__declspec(selectany) CoordinateFloat* MatrixCheckBoard[8][8];
