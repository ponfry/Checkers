#pragma once

struct FlagsGame
{
	bool FirstPlayerMove = true;
	bool SecondPlayerMove = false;
	bool BeginGame = true;
	bool EndGame = false;
};
__declspec(selectany) FlagsGame flags_game;