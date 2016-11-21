#pragma once
#include "DrawTexture.h"
#include "CoordinateFloat.h"

class ChessBoard
{
public:
	void Draw();
	ChessBoard();	
	bool CheckCoordinate();
	CoordinateFloat* GetEntryCoordinate();
private:
	void Init();
	DrawTexture* draw;
	CoordinateFloat coordinate[32];
};
