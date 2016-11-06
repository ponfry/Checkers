#pragma once
#include "il.h"
#include "glew.h"

#include "Helper.h"

class Texture
{
public:
	static unsigned int* Init()
	{
		unsigned int* textures = new unsigned int[2];
		ilGenImages(2, images);

		characteristics1 = Load(L"texture/bumaga.jpg", images[0]);
		characteristics2 = Load(L"texture/metall.jpg", images[1]);

		glGenTextures(2, textures);

		return textures;
	}
private:	
	static Characteristc Load(const wchar_t *filename, ILuint image)
	{
		ilBindImage(image);
		ilLoadImage(filename);
		result.texture = ilGetData();
		result.width = ilGetInteger(IL_IMAGE_WIDTH);
		result.height = ilGetInteger(IL_IMAGE_HEIGHT);
		result.type = ilGetInteger(IL_IMAGE_TYPE);
		result.format = ilGetInteger(IL_IMAGE_FORMAT);
		return result;
	}
};
