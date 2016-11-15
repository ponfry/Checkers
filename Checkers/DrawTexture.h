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
