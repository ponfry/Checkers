#pragma once
#include "ChessBoard.h"
#include "glew.h"
#include "Texture.h"

void ChessBoard::Draw() 
{
	draw = Texture::Init(L"texture/metall.jpg");
	glViewport(350, 100, 300, 300);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, draw->characteristic->width, draw->characteristic->height,
		0, draw->characteristic->format,draw-> characteristic->type, draw->characteristic->texture);

	int count = 0;
	float x = -0.75, y = -1.0;

	while (y < 1.0f)
	{
		while (x < 1.0f)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0, 1);
			glVertex2f(x, y);

			glTexCoord2f(0, 0);
			glVertex2f(x, y + 0.25f);

			glTexCoord2f(1, 1);
			glVertex2f(x + 0.25f, y);

			glTexCoord2f(1, 0);
			glVertex2f(x + 0.25f, y + 0.25f);
			glEnd();
			x += 0.5f;
		}
		count++;
		if (count % 2 == 0)
		{
			x = -0.75f;
		}
		else
		{
			x = -1.0f;
		}
		y += 0.25f;
	}
	glDisable(GL_TEXTURE_2D);
}

ChessBoard::ChessBoard()
{	
	
}
