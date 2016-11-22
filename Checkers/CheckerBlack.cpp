#include "CheckerBlack.h"
#include "Texture.h"

CheckerBlack::CheckerBlack()
{
	Init();
}
void CheckerBlack::Init()
{
	drawing = Texture::Init(L"blackChecker/checker.png");
	selecting = Texture::Init(L"blackChecker/select.png");
	lighting = Texture::Init(L"blackChecker/lighting.png");
}

bool CheckerBlack::CheckWalkCoordinate(CoordinateFloat* coordinate)
{
	coordinateCheck->Set(coordinateState->X + 0.25f, coordinateState->Y - 0.25f);
	if (coordinateCheck->CheckQuad(coordinate))
		return true;

	coordinateCheck->Set(coordinateState->X - 0.25f, coordinateState->Y - 0.25f);
	if (coordinateCheck->CheckQuad(coordinate))
		return true;

	return false;
}
