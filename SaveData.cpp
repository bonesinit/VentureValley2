/*
	File:		Character.cpp
	Author:		Joshua Strutt
*/

#include "SaveData.h"

void SaveData::saveGame(Player player)
{
	//Open file
	ofstream saveDataTxt{"saveData.txt"}; //opens file, makes one if the filename doesn't exist

	//Name
	saveDataTxt << "Name: " << player.name << "\n";

	//Stats
	saveDataTxt << "Stats: ";
	for (int i = 0; i < 5; i++)
	{
		saveDataTxt << player.stats[i];
		saveDataTxt << " ";
	}
	saveDataTxt << "\n";

	//Archetype
	saveDataTxt << "Archetype ID: " << player.archetype << "\n";

	//Items
	saveDataTxt << "Item IDs: ";
	for (int i = 0; i < 5; i++)
	{
		saveDataTxt << player.getItemID(i);
		saveDataTxt << " ";
	}
	saveDataTxt << "\n";

	//close file
	saveDataTxt.close();
	
}

void SaveData::loadGame(Player player)
{
	ifstream saveDataTxt{ "saveData.txt" };

	if (saveDataTxt.is_open())
	{
		//player should be created in the main at startup
		//read text file and set player.name, player.stats[i] in a for loop, and player.inventory[i] correctly in a for loop.
	}
	else
	{
		cout << "Unable to open file.\n";
	}

	saveDataTxt.close();
}