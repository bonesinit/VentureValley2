
/*
	File:		Building.h
	Author:		Anna Scheidl

	In this header and class file, the buildings will be created along with listing which characters are a part of these buildings.

*/
#pragma once
using namespace std;
#include <string>
#include <iostream>

class Building {
public:
	string buildingName;
	string descType;
	string characterList[3];
	bool visitedBuild;
	/* Example:
		1 - Blacksmith
				1 - Blacksmith
				2 - Apprentice
				3 - Shopper
		2 - Town Hall
				1 - Mayor
				2 - Guard
				3 - Irritated Townsperson
		3 - General Store
				1 - Shopkeeper
				2 - Shopper
				3 - Mysterious Stranger
		4 - Temple
				1 - Priest/Priestess
				2 - Person praying
				3 - Guard
		5 - Inn
				1 - Innkeeper
				2 - Drunkard
				3 - Random Villager
	*/

	void enterBuilding(int indexBuild);

};