#pragma once
#include "il.h"
#include <iostream>

struct WindowSize 
{
	int Weigth;
	int Heigth;
	int IndentX;
	int IndentY;
	int Board;

	WindowSize()
	{
		Weigth = 1300;
		Heigth = 650;
		IndentX = 230;
		IndentY = 37;
		Board = 575; 

	}

	void Set(int weigth, int heigth)
	{
		Weigth = weigth;
		Heigth = heigth;
		Board = Weigth / 2.26;
		IndentX = Board * 0.4;
		IndentY = (Heigth - Board - 33) / 2.0;
		std::cout << Weigth << "="<<Heigth << "=" << Board << "=" << IndentX << "=" << IndentY << std::endl;
	}

	bool CheckBoardHeigth(int weigth, int heigth)
	{
		return true;
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
	int X;
	int Y;
	void Set(int x, int y)
	{
		X = x;
		Y = y;
	}
};

struct CoordinateF
{
	float X;
	float Y;
	void Set(float x, float y)
	{
		X = x;
		Y = y;
	}
};

enum State
{
	draw = 0,
	notdraw,
	select
};