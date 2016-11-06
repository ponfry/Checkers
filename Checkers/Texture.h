#pragma once
#include "il.h"
#include "glew.h"
#include "Helper.h"
#include <iostream>

class Texture
{
public:
	static DrawTexture* Init(const wchar_t* filename)
	{
		ILuint *images = new ILuint;		
		unsigned int* textures = new unsigned int[2];
		Characteristic* characteristic = new Characteristic;

		ilGenImages(1, images);
		characteristic = Load(filename, *images);		
		glGenTextures(1, textures);
		
		return new DrawTexture(textures, characteristic);
	}
private:	
	static Characteristic* Load(const wchar_t* filename, ILuint image)
	{
		Characteristic* result = new Characteristic;
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
