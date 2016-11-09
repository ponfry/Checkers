#pragma once
#include "checker.h"
#include "glew.h"
#include "Texture.h"

void Checker::Draw(Coordinate coordinate)
{
	CoordinateF coordf = mouse_xy.ConvertIntTOFloat(coordinate.X, coordinate.Y);
	float x = coordf.X, y = coordf.Y;
	std::cout << x << "===" << y << std::endl;
	draw = Texture::Init(L"texture/checkerwhite.png");
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, draw->characteristic->width, draw->characteristic->height,
		0, draw->characteristic->format, draw->characteristic->type, draw->characteristic->texture);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(x - 0.125f, y - 0.125f);

	glTexCoord2f(0, 0);
	glVertex2f(x - 0.125f, y + 0.125f);

	glTexCoord2f(1, 1);
	glVertex2f(x + 0.125f, y - 0.125f);

	glTexCoord2f(1, 0);
	glVertex2f(x + 0.125f, y + 0.125f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

Checker::Checker(WindowSize* window_size)
{
	draw = nullptr;
	mouse_xy.Init(window_size);
}
