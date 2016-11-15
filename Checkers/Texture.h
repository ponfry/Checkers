#pragma once
#include "DrawTexture.h"

class Texture
{
public:
	static DrawTexture* Init(const wchar_t*);

private:	
	static Characteristic* Load(const wchar_t*, ILuint);
	
};
