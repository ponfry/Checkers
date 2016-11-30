#include "CheckerWhite.h"
#include "Texture.h"
#include "MatrixMove.h"
#include "Conversion.h"

CheckerWhite::CheckerWhite()
{
	CheckerWhite::Init();
}
void CheckerWhite::Init()
{
	drawing = Texture::Init(L"whiteChecker/checker.png");
	selecting = Texture::Init(L"whiteChecker/select.png");
	lighting = Texture::Init(L"whiteChecker/lighting.png");
}

void CheckerWhite::ControlMove()
{
	CoordinateInt* coord = Conversion::GetCoordinateForMatrix(coordinateState);
	countMove = 0;
	int coorr = MatrixGameField[coord->X + 1][coord->Y - 1];
	int coorr2 = MatrixGameField[coord->X - 1][coord->Y - 1];
	if (MatrixGameField[coord->X + 1][coord->Y - 1] == freely)
			countMove++;
	if (MatrixGameField[coord->X - 1][coord->Y - 1] == freely)
			countMove++;
	
}

bool CheckerWhite::CheckWalkCoordinate(CoordinateFloat* coordinate)
{
	coordinateCheck->Set(coordinateState->X + 0.25f, coordinateState->Y + 0.25f);
	if (coordinateCheck->CheckQuad(coordinate))
		return true;

	coordinateCheck->Set(coordinateState->X - 0.25f, coordinateState->Y + 0.25f);
	if (coordinateCheck->CheckQuad(coordinate))
		return true;

	return false;
}
