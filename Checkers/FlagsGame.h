#pragma once

struct FlagsGame
{
	bool FirstPlayerMove = true;
	bool SecondPlayerMove = false;
	bool BeginGame = true;
	bool EndGame = false;
	bool NewGame = false;
	bool Continue = false;

	void Reset()
	{
		FirstPlayerMove = true;
		SecondPlayerMove = false;
		BeginGame = true;
		EndGame = false;
		NewGame = false;
		Continue = false;
	}
};
__declspec(selectany) FlagsGame flags_game;