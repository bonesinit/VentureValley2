/*
	File:		Character.h
	Author:		Joshua Strutt
*/

#pragma once
using namespace std;
#include "TextAdventure.h"
#include "Character.h"


class SaveData {
public:
	
	//int questData[];
	//bool specialData[];

	//string playerName;
	//int playerStats[5]; //the saved stats
	//int playerInventory[5]; //holds the ids for the items
	
	void saveGame(Player player); //creates a notepad doc with savedata
	void loadGame(Player player); //loads in the notepad doc

};