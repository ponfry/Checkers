#pragma once
#include "CheckerBlack.h"
#include "CheckerWhite.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "ChessBoard.h"
#include "Menu.h"

class Game
{
public:
	Game();
	void Init();
	void InitDraw();

	void DrawWhoMove();
	void Redraw();

	void ControlPassive();
	void CheckPlayers();

	void CaptureCheckers();
private:
	void DrawCheckers();
	bool CheckFlags(FlagsPlayer*, Player*, Player*);

	ChessBoard* chess_board;
	PlayerTwo* playerTwo;
	PlayerOne* playerOne;

	CheckerWhite *checkerWhite;
	CheckerBlack *checkerBlack;
	float X, Y;
};
