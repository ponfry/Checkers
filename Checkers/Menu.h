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
	
	void DrawBegin();
	void DrawGameMenu();
	void DrawEndGame();
	void SetState(MenuState);
	void SetStateSelect();
	void Init();
private:
	
	ItemMenu *beginMenu, *gameMenu;
	float X, Y, offset;
};
__declspec(selectany) Menu menu;