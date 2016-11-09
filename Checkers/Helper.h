#pragma once
#include "il.h"

struct WindowSize 
{
	int Weigth;
	int Heigth;
	WindowSize()
	{
		Weigth = 1300;
		Heigth = 650;
	}
	void Set(int weigth, int heigth)
	{
		Weigth = weigth;
		Heigth = heigth;
	}
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

struct Coordinate
{
	int X, Y;
	void Set(int x, int y)
	{
		X = x;
		Y = y;
	}
};

struct CoordinateF
{
	float X, Y;
	void Set(float x, float y)
	{
		X = x;
		Y = y;
	}
};