#include "CheckerWhite.h"
#include "Texture.h"

CheckerWhite::CheckerWhite()
{
	Init();
}
void CheckerWhite::Init()
{
	drawing = Texture::Init(L"whiteChecker/checker.png");
	selected = Texture::Init(L"whiteChecker/select.png");
	lighting = Texture::Init(L"whiteChecker/lighting.png");
}
