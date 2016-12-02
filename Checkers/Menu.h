#pragma once
#include "MenuState.h"
#include "ItemMenu.h"

class Menu
{
public:
	Menu();
	bool CheckContactCoordinate();
	void ControlPassive();
	
	
	void DrawBegin();
	void DrawGameMenu();
	void DrawEndGame();
	void SetState(MenuState);

private:
	void Init();
	MenuState state;
	ItemMenu *beginMenu, *gameMenu;
};
__declspec(selectany) Menu menu;