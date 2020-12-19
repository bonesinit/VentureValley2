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
#include <algorithm>

using namespace std;

class Menu
{
public:
	//character creation
	string playerName;
	int playerArchetype = 0;
	int playerStrength = 1;
	int playerAgility = 1;
	int playerIntelligence = 1;
	int playerCharisma = 1;
	int playerLuck = 1;
	const int maxStatPoints = 15; //not counting the minimum of 1 for all the stats, meaning an effect 10 to spend
	int statPointsRemaining;
	bool doneAllocating = false;
	int statChoice;
	
	//general menus
	int printMenu(int type);

	int cinIntMinMax(int toCin, int min, int max); //min and max are inclusive. reusable function to cin and set a max or minimum for an int.
};

