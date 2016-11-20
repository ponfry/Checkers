#include "CheckerWhite.h"
#include "Texture.h"

CheckerWhite::CheckerWhite()
{
	Init();
}
void CheckerWhite::Init()
{
	draw = Texture::Init(L"whiteChecker/checker.png");
	select = Texture::Init(L"whiteChecker/select.png");
	lighting = Texture::Init(L"whiteChecker/lighting.png");
}
