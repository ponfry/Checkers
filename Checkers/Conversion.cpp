#include "Conversion.h"
#include "MatrixMove.h"

CoordinateInt* Conversion::GetCoordinateForMatrix(CoordinateFloat *coordinate)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(MatrixCheckBoard[i][j].CheckQuad(coordinate))
			{
				CoordinateInt* result = new CoordinateInt(i, j);
				return result;
			}
		}
	}
	return nullptr;	
}

void Conversion::Init()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			MatrixGameField[i][j] = freely;
		}
		for (int j = 0; j < 8; j += 2)
		{
			if (i % 2 == 0)
			{
				MatrixGameField[i][j] = incorrect;
			}
			else
			{
				MatrixGameField[i][j + 1] = incorrect;
			}
		}
	}

	float offset = 0.25, xset = -0.875, yset = 0.875;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			MatrixCheckBoard[i][j] = CoordinateFloat(xset + offset*j, yset - offset*i);
		}
	}
}
