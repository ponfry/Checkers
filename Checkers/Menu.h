#pragma once
#include "MenuState.h"
#include "ItemMenu.h"

class Menu
{
public:
	Menu();
	bool CheckContactCoordinate();
	void ControlPassive();
	void CaptureItemMenu();
	void SetNewCoordinate();

	void DrawBegin();
	void DrawGameMenu();
	void DrawEndGame();
	void SetState(MenuState);
	void SetStateSelect();
	void Init();
private:
	
	ItemMenu *beginMenu, *gameMenu, *endMenu;
	float X, Y, offset;
	int Xi, Yi, offseti;
};
__declspec(selectany) Menu menu;