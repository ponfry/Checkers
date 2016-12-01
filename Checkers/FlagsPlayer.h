#pragma once
#include "MatrixMove.h"

struct FlagsPlayer
{
	bool CaptureChecker = false;
	bool CheckChessBoardCoordinate = false;
	bool WasSetNewCoordinate = false;
	bool WasDeleteCheckerOtherPlayer = false;
	bool WasBeat = false;
	bool MustBeat = false;
	StateGameField Enemy = incorrect;

	bool CheckAll()
	{
		if(CaptureChecker && CheckChessBoardCoordinate && WasSetNewCoordinate)	
		{
			if (WasBeat)
			{
				if(WasDeleteCheckerOtherPlayer)
				{
					return true;
				}
				return false;
			}				
			return true;
		}
		return false;
	}
	void SetFalseAll()
	{
		CaptureChecker = false;
		CheckChessBoardCoordinate = false;
		WasSetNewCoordinate = false;
		WasDeleteCheckerOtherPlayer = false;
		WasBeat = false;
	}
};

__declspec(selectany) FlagsPlayer flags_player_one;
__declspec(selectany) FlagsPlayer flags_player_two;
