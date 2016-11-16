#pragma once
#include "DrawTexture.h"

class ChessBoard
{
public:
	void Draw();
	ChessBoard();
	void Init();
private:
	DrawTexture* draw;
};
