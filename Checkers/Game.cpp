#include "Game.h"
#include "glut.h"
#include "WindowSize.h"
#include "Texture.h"
#include "ControlMatrix.h"
#include "FlagsGame.h"
#include "TypeError.h"
#include "MyErrors.h"

Game::Game()
{
	chess_board = nullptr;
	playerTwo = nullptr;
	playerOne = nullptr;

	checkerWhite = nullptr;
	checkerBlack = nullptr;

	X = 0;
	Y = 0;
}

void Game::Init()
{
	flags_game.Reset();
	WhiteDrawing = Texture::Init(L"whiteChecker/checker.png");
	WhiteSelecting = Texture::Init(L"whiteChecker/select.png");
	WhiteLighting = Texture::Init(L"whiteChecker/lighting.png");

	BlackDrawing = Texture::Init(L"blackChecker/checker.png");
	BlackLighting = Texture::Init(L"blackChecker/lighting.png");
	BlackSelecting = Texture::Init(L"blackChecker/select.png");

	drawErrorWrong = Texture::Init(L"errors/ErrorWrongMove.png");
	drawErrorBeat = Texture::Init(L"errors/ErrorBeat.png");
	drawEnd = Texture::Init(L"EndGame.png");

	menuLighting = Texture::Init(L"menu/MenuP.png");	
	menuDrawing = Texture::Init(L"menu/Menu.png");	

	newGameDrawing = Texture::Init(L"menu/NewGame.png");
	newGameLighting = Texture::Init(L"menu/NewGameP.png");

	continueDrawing = Texture::Init(L"menu/Continue.png");
	continueLighting = Texture::Init(L"menu/ContinueP.png");

	
	menu.SetState(drawing);
	

	ControlMatrix::Init();
	flags_player_one.Enemy = black;
	flags_player_two.Enemy = white;	

	chess_board = new ChessBoard();
	playerOne = new PlayerOne();
	playerTwo = new PlayerTwo();	
	
	checkerWhite = new CheckerWhite();
	checkerBlack = new CheckerBlack();

	checkerWhite->SetCoordinates(-0.1f, 0.3f);
	checkerBlack->SetCoordinates(0.6f, 0.3f);

	checkerWhite->SetState(constant);
	menu.Init();
}

void Game::InitDraw()
{
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	
	X = (-2) * (window_size.Weigth / 2.0 - 163) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 33) / window_size.Heigth;


	glViewport(window_size.Weigth - window_size.Heigth, 0, window_size.Heigth, window_size.Heigth);
	checkerWhite->Draw();
	checkerBlack->Draw();

	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();
	
	menu.DrawGameMenu();
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

	glViewport(window_size.Weigth - window_size.Heigth, 0, window_size.Heigth, window_size.Heigth);
	checkerWhite->Draw();
	checkerBlack->Draw();


	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();

	menu.DrawGameMenu();
	glutSwapBuffers();
}

void Game::DrawWhoMove()
{
	glViewport(window_size.Weigth - window_size.Heigth, 0, window_size.Heigth, window_size.Heigth);
	
	if (flags_game.FirstPlayerMove)
	{
		checkerWhite->SetState(constant);
		checkerBlack->SetState(draw);
	}
	if (flags_game.SecondPlayerMove)
	{
		checkerWhite->SetState(draw);
		checkerBlack->SetState(constant);
	}
	DrawCheckers();

	glViewport(window_size.IndentX, window_size.IndentY,
		window_size.Board, window_size.Board);
}

void Game::Redraw()
{
	glViewport(window_size.IndentX, window_size.IndentY,
		window_size.Board, window_size.Board);

	if (!flags_game.EndGame)
	{
		chess_board->Draw();
		if (flags_game.FirstPlayerMove)
		{
			playerTwo->Draw();
			playerOne->Draw();
		}
		if (flags_game.SecondPlayerMove)
		{
			playerOne->Draw();
			playerTwo->Draw();
		}
		DrawWhoMove();

		glutSwapBuffers();
	}
	else
	{
		Errors::Draw(endGame);
	}
}

void Game::ControlPassive()
{
	if (!flags_game.EndGame)
	{
		if (flags_game.FirstPlayerMove)
		{
			playerOne->CheckCoordinatePassive();
		}
		if (flags_game.SecondPlayerMove)
		{
			playerTwo->CheckCoordinatePassive();
		}
		Redraw();
	
	}
	else
	{
		Errors::Draw(endGame);
	}
}

void Game::CheckPlayers()
{
	if (!flags_game.EndGame)
	{
		if (flags_game.FirstPlayerMove)
		{
			if (flags_player_one.CaptureChecker &&
				CheckFlags(&flags_player_one, playerOne, playerTwo))
			{
				flags_game.FirstPlayerMove = false;
				flags_game.SecondPlayerMove = true;
			}
		}

		if (flags_game.SecondPlayerMove)
		{
			if (flags_player_two.CaptureChecker &&
				CheckFlags(&flags_player_two, playerTwo, playerOne))
			{
				flags_game.FirstPlayerMove = true;
				flags_game.SecondPlayerMove = false;
			}
		}
	}
}

void Game::CaptureCheckers()
{
	if (!flags_game.EndGame)
	{
		if (flags_game.FirstPlayerMove)
		{
			flags_player_one.CaptureChecker = playerOne->SetStateSelectChecker();
		}
		if (flags_game.SecondPlayerMove)
		{
			flags_player_two.CaptureChecker = playerTwo->SetStateSelectChecker();
		}
	}
}

void Game::DrawCheckers()
{
	checkerWhite->Draw();
	checkerBlack->Draw();
}

bool Game::CheckFlags(FlagsPlayer* flagplayer, Player* player, Player* player1)
{
	bool resultB = true;
	if (flagplayer->CaptureChecker)
	{
		flagplayer->CheckChessBoardCoordinate = chess_board->CheckCoordinate();
		if (flagplayer->CheckChessBoardCoordinate)
		{
			CoordinateFloat* result = chess_board->GetEntryCoordinate();
			player->ControlMovesCheckers();

			flagplayer->WasSetNewCoordinate = player->SetNewCoordinateChecker(result);

			if (flagplayer->WasBeat)
			{
				flagplayer->WasDeleteCheckerOtherPlayer = player1->SetStateNotDrawChecker();
			}

		}

		if (!flagplayer->CheckAll())
		{
			player->SetStateUnSelectChecker();
			if (flagplayer->MustBeat)
			{
				flagplayer->MustBeat = false;
				Errors::Draw(wrongMove);
				Errors::Draw(beatMove);
			}
			else
			{
				Errors::Draw(wrongMove);
			}
			resultB = false;
		}
	}
	if (player->ControlCheckers() > 11 || player1->ControlCheckers()>11)
	{
		flags_game.EndGame = true;
		return false;
	}
	flagplayer->SetFalseAll();
	return resultB;
}
