#pragma once
#include "DrawTexture.h"

class Texture
{
public:
	static DrawTexture* Init(const wchar_t*);
	static void LoadDraw(DrawTexture*);
private:	
	static Characteristic* Load(const wchar_t*, ILuint);
	
};
