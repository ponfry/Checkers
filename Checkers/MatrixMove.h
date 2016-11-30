#pragma once
enum StateGameField
{
	busy = 0,
	freely,
	incorrect
};

__declspec(selectany) StateGameField MatrixGameField[8][8];
__declspec(selectany) int SizeMatrix = 8 ;

