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

	void addItem(int index, Item toAdd);
	void destroyItem(int index);
	void moveItem(int indexFrom, int indexTo);
	Item dropItem(int index); //removes item from inventory, but the function returns it. could be useful when transferring items to another object.
};

class Vendor : public Character {
public:
	string interactionDialogues[3];

	Item buyables[5]; 

	void addItem(int index, Item toAdd);
	void destroyItem(int index);
	void moveItem(int indexFrom, int indexTo);
	int getBuyableCost(int index);

	void printDialogue();
};