/*
	File:		Character.cpp
	Author:		Joshua Strutt
*/

#include "Character.h"


//	Player
int Player::getItemID(int index)
{
	return inventory[index].id;
}

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

bool Player::skillCheckChance(int statIndex, int numToBeat) {
	if (statIndex == 4) {
		if (stats[statIndex] >= numToBeat) {
			return true;
		}
	}
	else if (stats[statIndex] + rand() % (stats[4] + 1) >= numToBeat)
	{
		return true;
	}
	return false;
}

bool Player::skillCheck(int statIndex, int numToBeat) {
	if (stats[statIndex] >= numToBeat) {
		return true;
	}
	return false;
}

void Player::printInventory() {
	cout << "Inventory:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ": " << inventory[i].name << endl;
	}
}

void Player::printStats() {
	cout << "Stats:" << endl;
	cout << "Strength: " << stats[0] << " | Agility: " << stats[1] << " | Intelligence: " << stats[2] << " | Charisma: " << stats[3] << " | Luck: " << stats[4] << endl;
}

void Player::printInventoryStats() {
	cout << "Inventory:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ": " << inventory[i].name << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "Stats:" << endl;
	cout << "Strength: " << stats[0] << " | Agility: " << stats[1] << " | Intelligence: " << stats[2] << " | Charisma: " << stats[3] << " | Luck: " << stats[4] << endl;
}

Player::Player() {
	id = 0;
}


//	Vendor
int Vendor::getBuyableID(int index)
{
	return buyables[index].id;
}

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



//Constructors
Vendor::Vendor() {

}

Vendor::Vendor(int id) {
	id = id;
}

Vendor::Vendor(int id, string name) {
	id = id;
	name = name;
}

//Constuctor for a pregiven list of items. Could be useful.
Vendor::Vendor(int id, string name, Item items[]) {
	id = id;
	name = name;
	for (int i = 0; i < 5; i++)
	{
		buyables[i] = items[i];
	}
}


//Constructors for single items
Vendor::Vendor(int id, string name, Item item1) {
	id = id;
	name = name;
	buyables[0] = item1;
}

Vendor::Vendor(int id, string name, Item item1, Item item2) {
	id = id;
	name = name;
	buyables[0] = item1;
	buyables[1] = item2;
}

Vendor::Vendor(int id, string name, Item item1, Item item2, Item item3) {
	id = id;
	name = name;
	buyables[0] = item1;
	buyables[1] = item2;
	buyables[2] = item3;
}

Vendor::Vendor(int id, string name, Item item1, Item item2, Item item3, Item item4) {
	id = id;
	name = name;
	buyables[0] = item1;
	buyables[1] = item2;
	buyables[2] = item3;
	buyables[3] = item4;
}

Vendor::Vendor(int id, string name, Item item1, Item item2, Item item3, Item item4, Item item5) {
	id = id;
	name = name;
	buyables[0] = item1;
	buyables[1] = item2;
	buyables[2] = item3;
	buyables[3] = item4;
	buyables[4] = item5;
}
