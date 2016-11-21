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

void Texture::LoadDraw(DrawTexture* draw)
{
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, draw->characteristic->width,
		draw->characteristic->height,
		0, draw->characteristic->format,
		draw->characteristic->type,
		draw->characteristic->texture);
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
