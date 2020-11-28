/*
	File:		Character.cpp
	Author:		Joshua Strutt
*/

#include "Character.h"


//	Player
void Player::addItem(int index, Item toAdd)
{
	inventory[index] = toAdd;
}

Item Player::dropItem(int index)
{
	Item temp = inventory[index];

	Item nullItem;
	nullItem.id = -1;
	inventory[index] = nullItem;

	return temp;
}

void Player::destroyItem(int index)
{
	Item nullItem;
	nullItem.id = -1;
	inventory[index] = nullItem;
}

void Player::moveItem(int indexFrom, int indexTo)
{
	Item temp = inventory[indexTo];
	inventory[indexTo] = inventory[indexFrom];
	inventory[indexFrom] = inventory[indexTo];
}


//	Vendor
void Vendor::addItem(int index, Item toAdd)
{
	buyables[index] = toAdd;
}

void Vendor::destroyItem(int index)
{
	Item nullItem;
	nullItem.id = -1;
	buyables[index] = nullItem;
}

void Vendor::moveItem(int indexFrom, int indexTo)
{
	Item temp = buyables[indexTo];
	buyables[indexTo] = buyables[indexFrom];
	buyables[indexFrom] = buyables[indexTo];

}

int Vendor::getBuyableCost(int index)
{
	return buyables[index].cost;
}

void Vendor::printDialogue()
{
	cout << interactionDialogues[rand() % 3] << endl;
}
