#pragma once

struct FlagsPlayer
{
	bool CaptureChecker = false;
	bool CheckChessBoardCoordinate = false;
	bool WasSetWalkCoordinateChecker = false;
	bool WasSetBeatCoordinateChecker = false;
	bool IsConflictOtherPlayerCheckers = false;
	bool CheckAll()
	{
		if(CaptureChecker && CheckChessBoardCoordinate && (WasSetWalkCoordinateChecker || WasSetBeatCoordinateChecker)&& !IsConflictOtherPlayerCheckers)
		{
			return true;
		}
		return false;
	}
	void SetFalseAll()
	{
		CaptureChecker = false;
		CheckChessBoardCoordinate = false;
		WasSetWalkCoordinateChecker = false;
		WasSetBeatCoordinateChecker = false;
		IsConflictOtherPlayerCheckers = false;
	}
};

__declspec(selectany) FlagsPlayer flags_player_one;
__declspec(selectany) FlagsPlayer flags_player_two;