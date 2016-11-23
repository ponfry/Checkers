﻿#pragma once

struct FlagsGame
{
	bool CaptureChecker = false;
	bool CheckChessBoardCoordinate = false;
	bool WasSetCoordinateChecker = false;
	bool IsConflictOtherPlayerCheckers = false;
	bool CheckAll()
	{
		if(CaptureChecker && CheckChessBoardCoordinate && WasSetCoordinateChecker && !IsConflictOtherPlayerCheckers)
		{
			return true;
		}
		return false;
	}
	void SetFalseAll()
	{
		CaptureChecker = false;
		CheckChessBoardCoordinate = false;
		WasSetCoordinateChecker = false;
		IsConflictOtherPlayerCheckers = false;
	}
};

__declspec(selectany) FlagsGame flags_player_one;
__declspec(selectany) FlagsGame flags_player_two;