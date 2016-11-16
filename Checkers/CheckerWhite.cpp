#include "CheckerWhite.h"
#include "Texture.h"

CheckerWhite::CheckerWhite()
{
	Init();
}
void CheckerWhite::Init()
{
	draw = Texture::Init(L"texture/checkerwhite.png");
}
