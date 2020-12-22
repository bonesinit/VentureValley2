/*
	File:		Character.h
	Author:		Joshua Strutt
*/

#pragma once
using namespace std;
#include "TextAdventure.h"
#include "Item.h"


class Character {
public:
	int id;
	string name;
	int gold;
};


class Player : public Character {
public:
	int archetype;
	/*
		archetype index:
			0 - Warrior
			1 - Rogue
			2 - Ranger
			3 - Mage
			4 - Bard
			5 - Necromancer
			6 - Shaman/Druid
	*/

	int stats[5];
	/*
		stats index:
			0 - Strength
			1 - Agility
			2 - Intelligence
			3 - Charisma
			4 - Luck
	*/

	Item inventory[5]; //placeholder number. possibility of adding a backpack class too in the future.

	int getItemID(int index);
	void addItem(int index, Item toAdd);
	void destroyItem(int index);
	void moveItem(int indexFrom, int indexTo);
	Item dropItem(int index); //removes item from inventory, but the function returns it. could be useful when transferring items to another object.

	bool skillCheckChance(int statIndex, int numToBeat); //true if chosen stat + random num between 1 and luck stat beats numToBeat
	bool skillCheck(int statIndex, int numToBeat); //tests stat against numtoBeat

	void printInventory();
	void printStats();
	void printInventoryStats();

	Player(); //no cosntructors needed since only one player is ever instantiated
};

class Vendor : public Character {
public:
	string interactionDialogues[3];

	Item buyables[5]; 

	int getBuyableID(int index);
	void addItem(int index, Item toAdd);
	void destroyItem(int index);
	void moveItem(int indexFrom, int indexTo);
	int getBuyableCost(int index);

	void printDialogue(); //prints a random dialogue option from a given list

	Vendor();
	Vendor(int id);
	Vendor(int id, string name);
	Vendor(int id, string name, Item items[]);
	Vendor(int id, string name, Item item1);
	Vendor(int id, string name, Item item1, Item item2);
	Vendor(int id, string name, Item item1, Item item2, Item item3);
	Vendor(int id, string name, Item item1, Item item2, Item item3, Item item4);
	Vendor(int id, string name, Item item1, Item item2, Item item3, Item item4, Item item5);
};