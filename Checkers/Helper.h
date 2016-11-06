#pragma once
#include "il.h"

static class WindowSize 
{
public: 
	static const int Weigth = 1000;
	static const int Heigth = 500;
};

struct Characteristc
{
	ILubyte* texture;
	ILuint width;
	ILuint height;
	ILuint type;
	ILuint format;
};

ILuint *images = new ILuint[2];
Characteristc characteristics1, characteristics2, result;