#pragma once
#include "MyErrors.h"
#include "Texture.h"
#include "glew.h"
#include "glut.h"
#include <windows.h>

void Errors::Draw(TypeErrors type)
{
	float X, Y;
	switch (type)
	{
	case wrongMove:
		Texture::LoadDraw(drawErrorWrong);
		X = 0.5f;
		Y = 0.25f;
		break;

	case beatMove:
		Texture::LoadDraw(drawErrorBeat);
		X = 0.5f;
		Y = 0.25f;
		break;

	case endGame:
		Texture::LoadDraw(drawEnd);
		X = 1.0f;
		Y = 1.0f;
		break;

	default:
		X = 0;
		Y = 0;
		break;
	}
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(-X, -Y);

	glTexCoord2f(0, 0);
	glVertex2f(-X, Y);

	glTexCoord2f(1, 1);
	glVertex2f(X, -Y);

	glTexCoord2f(1, 0);
	glVertex2f(X, Y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glutSwapBuffers();
	Sleep(1150);
}
