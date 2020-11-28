/*
	File:		Menu.h
	Author:		Brandon White

	Documentation:
	-----
	-	The menu works by switching to menu mode and then choosing a menu to view based on the menu type designated in main.
	-	To call a pause screen menu while in a village, you would do something like this:
		
		menuType = 3;
		inGame = false;

	-	Then when the game makes its next loop, it'll switch to the menu and go to menuType 3 (pause).
*/

#pragma once

#include "TextAdventure.h"

using namespace std;

class Menu
{
public:
	int printMenu(int type);
};

