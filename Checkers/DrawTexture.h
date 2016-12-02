#pragma once
#include "Characterictics.h"

struct DrawTexture
{
	unsigned int* textures;
	Characteristic* characteristic;
	DrawTexture(unsigned int* texture,
		Characteristic* characteristi)
	{
		textures = texture;
		characteristic = characteristi;
	}
};
__declspec(selectany) DrawTexture *WhiteDrawing;
__declspec(selectany) DrawTexture *WhiteSelecting;
__declspec(selectany) DrawTexture *WhiteLighting;

__declspec(selectany) DrawTexture *BlackDrawing;
__declspec(selectany) DrawTexture *BlackLighting;
__declspec(selectany) DrawTexture *BlackSelecting;

__declspec(selectany) DrawTexture *drawErrorWrong;
__declspec(selectany) DrawTexture *drawErrorBeat;
__declspec(selectany) DrawTexture *drawEnd;

__declspec(selectany) DrawTexture *menuDrawing;
__declspec(selectany) DrawTexture *menuLighting;	
