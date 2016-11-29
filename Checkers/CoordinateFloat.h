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
	bool operator ==(CoordinateFloat* coordinateone)
	{
		if(coordinateone->X == X && coordinateone->Y == Y)
		{
			return true;
		}
		return false;
	}
};

__declspec(selectany) CoordinateFloat startBeatCoordinateChecker;
__declspec(selectany) CoordinateFloat endBeatCoordinateChecker;
__declspec(selectany) CoordinateFloat MatrixCheckBoard[8][8];
