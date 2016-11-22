#include "CheckerWhite.h"
#include "Texture.h"

CheckerWhite::CheckerWhite()
{
	Init();
}
void CheckerWhite::Init()
{
	drawing = Texture::Init(L"whiteChecker/checker.png");
	selecting = Texture::Init(L"whiteChecker/select.png");
	lighting = Texture::Init(L"whiteChecker/lighting.png");
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
