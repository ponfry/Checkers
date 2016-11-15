#include "Texture.h"
#include "glew.h"


DrawTexture* Texture::Init(const wchar_t* filename)
{
	ILuint *images = new ILuint;
	unsigned int* textures = new unsigned int[2];
	Characteristic* characteristic = new Characteristic;

	ilGenImages(1, images);
	characteristic = Load(filename, *images);
	glGenTextures(1, textures);

	return new DrawTexture(textures, characteristic);
}

Characteristic* Texture::Load(const wchar_t* filename, ILuint image)
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
