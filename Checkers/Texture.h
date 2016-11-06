#pragma once
#include "il.h"
#include "glew.h"
#include "Helper.h"
#include <iostream>
#include <stdio.h>

class Texture
{
public:
	static Draw* Init(const wchar_t* filename)
	{
		ILuint *images = new ILuint;
		Draw* draw = new Draw;
		unsigned int* textures = new unsigned int[2];
		ilGenImages(1, images);

		draw->characteristic = Load(filename, *images);
		
		glGenTextures(1, textures);
		
		draw->textures = textures;
		return draw;
	}
private:	
	static Characteristc* Load(const wchar_t* filename, ILuint image)
	{
		Characteristc* result = new Characteristc;
		ilBindImage(image);
		ilLoadImage(filename);
		
		result->texture = ilGetData();
		result->width = ilGetInteger(IL_IMAGE_WIDTH);
		result->height = ilGetInteger(IL_IMAGE_HEIGHT);
		result->type = ilGetInteger(IL_IMAGE_TYPE);
		result->format = ilGetInteger(IL_IMAGE_FORMAT);
		return result;
	}
};
