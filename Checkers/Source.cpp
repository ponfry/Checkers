#include <iostream>
#include <windows.h>
#include "glew.h"
#include "glut.h"
#include "WindowSize.h"
#include "ChessBoard.h"
#include "CoordinateInt.h"
#include "CoordinateFloat.h"
#include "Texture.h"
#include "FlagsPlayer.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "MatrixMove.h"

#include <ctime>    
using namespace std;

ChessBoard* chess_board;
PlayerTwo* playerTwo;
PlayerOne* playerOne;

DrawTexture* drawErrorWrong, *drawErrorPlayer;

CheckerWhite *checkerWhite;
CheckerBlack *checkerBlack;

float X, Y;

struct FlagsGame
{
	bool FirstPlayerMove = true;
	bool SecondPlayerMove = false;
	bool BeginGame = false;
}flags_game;

void Textout(char* str, float X, float Y, float phi = 0.02)
{
	int i = 2;
	glRasterPos2f(X, Y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[0]);

	while (str[i - 1] != '\0')
	{
		glRasterPos2f(X + i * phi, Y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i - 1]);
		i++;
	}
}

void Textout(char* str, CoordinateFloat coordf, float phi = 0.02)
{
	Textout(str, coordf.X, coordf.Y, phi);
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	
	X = (-2) * (window_size.Weigth / 2.0 - 163) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 33) / window_size.Heigth;

	glColor3f(1.0f, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(X, 1.0f);
	glVertex2f(-1.0f, Y);
	glVertex2f(X, Y);
	glEnd();
	X = (-2) * (window_size.Weigth / 2.0 - 50) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 25) / window_size.Heigth;
	glColor3f(0, 0, 1);
	Textout("Menu", X, Y);

	glViewport(window_size.Weigth - window_size.Heigth, 0, window_size.Heigth, window_size.Heigth);

	checkerWhite->Draw();
	checkerBlack->Draw();

	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();

	glutSwapBuffers();
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();

	X = (-2) * (window_size.Weigth / 2.0 - 163) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 33) / window_size.Heigth;

	glColor3f(1.0f, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(X, 1.0f);
	glVertex2f(-1.0f, Y);
	glVertex2f(X, Y);
	glEnd();
	X = (-2) * (window_size.Weigth / 2.0 - 50) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 25) / window_size.Heigth;
	glColor3f(0, 0, 1);
	Textout("Menu", X, Y);

	glViewport(window_size.Weigth - window_size.Heigth, 0, window_size.Heigth, window_size.Heigth);

	checkerWhite->Draw();
	checkerBlack->Draw();

	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();

	glutSwapBuffers();
	
}

void drawError()
{
	Texture::LoadDraw(drawErrorWrong);
	
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, -0.25f);

	glTexCoord2f(0, 0);
	glVertex2f(-0.5f, 0.25f);

	glTexCoord2f(1, 1);
	glVertex2f(0.5f, -0.25f);

	glTexCoord2f(1, 0);
	glVertex2f(0.5f, 0.25f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glutSwapBuffers();
	Sleep(1150);
}

void drawErrorPlayers()
{
	Texture::LoadDraw(drawErrorPlayer);

	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, -0.25f);

	glTexCoord2f(0, 0);
	glVertex2f(-0.5f, 0.25f);

	glTexCoord2f(1, 1);
	glVertex2f(0.5f, -0.25f);

	glTexCoord2f(1, 0);
	glVertex2f(0.5f, 0.25f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glutSwapBuffers();
	Sleep(1150);
}

void reDrawCheckers()
{
	checkerWhite->Draw();
	checkerBlack->Draw();
}

void drawWhoMove()
{
	glViewport(window_size.Weigth-window_size.Heigth, 0, window_size.Heigth, window_size.Heigth);
	if (flags_game.FirstPlayerMove)
	{
		checkerWhite->SetState(constant);
		checkerBlack->SetState(draw);
		/*char title[20];
		sprintf_s(title, "%dx%dc%dx%d", window_size.Weigth, window_size.Heigth, coordinateMousePassiveMove.X, coordinateMousePassiveMove.Y);
		glutSetWindowTitle(title);*/
	}
	if (flags_game.SecondPlayerMove)
	{
		checkerWhite->SetState(draw);
		checkerBlack->SetState(constant);
	}
	reDrawCheckers();

	glViewport(window_size.IndentX, window_size.IndentY,
		window_size.Board, window_size.Board);
}

void reDraw()
{
	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();
	drawWhoMove();

	glutSwapBuffers();
}

void mouseActive(int x, int y)
{
	coordinateMouseMove.Set(x, y);
	reDraw();
}	

void mousePassive(int x, int y)
{
	coordinateMousePassiveMove.Set(x, y);
	if (flags_game.FirstPlayerMove)
	{
		playerOne->CheckCoordinatePassive();
	}
	if (flags_game.SecondPlayerMove)
	{
		playerTwo->CheckCoordinatePassive();
	}
	reDraw();
	
}

void ChangeWH(int w, int h)
{
	if (w > 500 && h > 300)
	{
		if (((h - w / 2.26 - 33) / 2.0) > 1)
		{
			window_size.Set(w, h);
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
	}
}

CoordinateFloat* Calculate()
{
	float x, y;
	x = startBeatCoordinateChecker.X - (startBeatCoordinateChecker.X - endBeatCoordinateChecker.X)/2;
	y = startBeatCoordinateChecker.Y - (startBeatCoordinateChecker.Y - endBeatCoordinateChecker.Y)/2;
	return new CoordinateFloat(x, y);
}

bool CheckFlags(FlagsPlayer* flagplayer, Player* player, Player* player1)
{
	bool resultB = true;
	if (flagplayer->CaptureChecker)
	{
		flagplayer->CheckChessBoardCoordinate = chess_board->CheckCoordinate();
		CoordinateFloat* result = chess_board->GetEntryCoordinate();

		flagplayer->IsConflictOtherPlayerCheckers = 
			player1->Check—onflictCoordinateCheckers(result);

		if (flagplayer->CheckChessBoardCoordinate && !flagplayer->IsConflictOtherPlayerCheckers)
		{
			flagplayer->WasSetWalkCoordinateChecker =
				player->SetWalkCoordinateSelectedChecker(result);

			player->InitStartEndBeatCoordinate(result);

			if(!flagplayer->WasSetWalkCoordinateChecker && player1->Check—onflictCoordinateCheckers(Calculate()))
			{
				flagplayer->WasSetBeatCoordinateChecker =
					player->SetBeatCoordinateSelectedChecker(result);

				player1->SetStateNotDrawChecker(Calculate());
			}

		}

		if (!flagplayer->CheckAll())
		{
			player->SetStateUnSelectChecker();
			drawError();
			resultB = false;
		}
	}
	flagplayer->SetFalseAll();
	return resultB;
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		coordinateMouseMove.Set(x,y);
		if (flags_game.FirstPlayerMove)
		{
			flags_player_one.CaptureChecker = playerOne->SetStateSelectChecker();
		}
		if (flags_game.SecondPlayerMove)
		{
			flags_player_two.CaptureChecker = playerTwo->SetStateSelectChecker();
		}
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		coordinateMouseMove.Set(x, y);
		if(flags_player_one.CaptureChecker && CheckFlags(&flags_player_one, playerOne, playerTwo))
		{
			flags_game.FirstPlayerMove = false;
			flags_game.SecondPlayerMove = true;			
		}

		if (flags_player_two.CaptureChecker && CheckFlags(&flags_player_two, playerTwo, playerOne))
		{
			flags_game.FirstPlayerMove = true;
			flags_game.SecondPlayerMove = false;
		}
	}
	reDraw();
}

void InitGame()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			MatrixGameField[i][j] = freely;
		}	

		for (int j = 0; j < 8; j += 2)
		{
			if (i % 2 == 0)
			{
				MatrixGameField[i][j] = incorrect;
			}
			else
			{
				MatrixGameField[i][j + 1] = incorrect;
			}
		}
		
	}
	
	playerTwo = new PlayerTwo();
	playerOne = new PlayerOne();
	chess_board = new ChessBoard();
	drawErrorWrong = Texture::Init(L"errors/ErrorWrongMove.png");
	drawErrorPlayer = Texture::Init(L"errors/ErrorPlayer.png");
	checkerWhite = new CheckerWhite();
	checkerBlack = new CheckerBlack();

	checkerWhite->SetCoordinate(0.4f, -0.7f);
	checkerBlack->SetCoordinate(0.8f, -0.7f);

	checkerWhite->SetState(constant);
	
	/*cout << busy << incorrect << freely<< endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << MatrixGameField[i][j] <<" ";		
		}
		cout << endl;
	}*/
}
void main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
	glutCreateWindow("Checkers");

	ilInit();
	InitGame();

	glutMotionFunc(mouseActive);
	glutPassiveMotionFunc(mousePassive);
	glutMouseFunc(mouse);
	glutDisplayFunc(init);
	glutReshapeFunc(ChangeWH);
	glewInit();
	
	glutMainLoop();
	
}


/*char title[20];
sprintf_s(title, "%dx%dc%dx%d", window_size.Weigth, window_size.Heigth, coordinateMousePassiveMove.X, coordinateMousePassiveMove.Y);

glutSetWindowTitle(title);*/

//clock_t start, finish;
//start = clock();
//finish = clock();
//cout << "time=";
//cout << (finish - start) << endl;
