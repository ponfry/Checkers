#include <iostream>
#include <windows.h>
#include "glew.h"
#include "glut.h"

#include "WindowSize.h"
#include "FlagsGame.h"
#include "Game.h"
#include "MyErrors.h"
#include <ctime>
#include "Menu.h"

using namespace std;

Game game;

void mouseActive(int x, int y)
{
	coordinateMouseMove.Set(x, y);
	game.Redraw();
	glutSwapBuffers();
}	

void mousePassive(int x, int y)
{
	coordinateMousePassiveMove.Set(x, y);
	
	menu.ControlPassive();
	game.ControlPassive();

	if (flags_game.EndGame)
	{
		Errors::Draw(endGame);
		menu.DrawEndGame();
	}
	glutSwapBuffers();

	
	/*char title[20];
	sprintf_s(title, "%dx%d", coordinateMousePassiveMove.X, coordinateMousePassiveMove.Y);

	glutSetWindowTitle(title);*/
	
}

void ChangeWH(int w, int h)
{
	if (w > 500 && h > 300)
	{
		if (((h - w / 2.26 - 33) / 2.0) > 1)
		{
			window_size.Set(w, h);
			menu.SetNewCoordinate();
		}
		else
		{
			glutReshapeWindow(window_size.Weigth, window_size.Heigth);
		}
	}
	else
	{
		window_size.Set(501, 301);
		glutReshapeWindow(window_size.Weigth, window_size.Heigth);
		menu.SetNewCoordinate();
	}
	
}

void mouse(int button, int state, int x, int y)
{
	coordinateMouseMove.Set(x, y);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(!flags_game.EndGame)
		{
			game.CaptureCheckers();
		}
		
		menu.CaptureItemMenu();
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (!flags_game.EndGame)
		{
			game.CheckPlayers();
		}
		if (flags_game.NewGame)
		{
			flags_game.NewGame = false;
			game.Reset();
		}
		if (flags_game.Continue)
		{
			flags_game.Continue = false;
			menu.SetState(drawing);
		}
	}

	if(flags_game.EndGame)
	{
		Errors::Draw(endGame);
		menu.DrawEndGame();
	}
	else
	{		
		menu.DrawGameMenu();
		game.Redraw();
	}
	glutSwapBuffers();
}

void init()
{
	if (flags_game.EndGame)
	{
		Errors::Draw(endGame);
		menu.DrawEndGame();
	}
	else
	{
		game.InitDraw();
	}
	if(flags_game.NewGame)
	{
		flags_game.NewGame = false;
		game.Init();
	}
}

void main(int argc, char* argv[])
{	
	clock_t start, finish;
	start = clock();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
	glutCreateWindow("Checkers");

	ilInit();
	game.Init();

	glutMotionFunc(mouseActive);
	glutPassiveMotionFunc(mousePassive);
	glutMouseFunc(mouse);
	glutDisplayFunc(init);
	glutReshapeFunc(ChangeWH);
	glewInit();
	finish = clock();
	cout << "time load=";
	cout << (finish - start) << endl;
	glutMainLoop();	
}

