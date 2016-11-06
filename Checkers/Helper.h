#pragma once
#include "il.h"

struct WindowSize 
{
	int Weigth = 1000;
	int Heigth = 500;
};

struct Characteristic
{
	ILubyte* texture;
	ILuint width;
	ILuint height;
	ILuint type;
	ILuint format;
};
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