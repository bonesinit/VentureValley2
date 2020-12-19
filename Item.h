/*
	File:		Item.h
	Author:		Anna Scheidl
*/

#pragma once
using namespace std;
#include <string>
#include <iostream>

class Item {
public:
	int id;
	string name;
	string descItem;
	bool uniqueToClass[5];
	bool notUsedBy[5];
	int itemStats;
	bool hasItem;

	int cost;

	void printInfo(int itemIndex);
	void setDescription(string description); //description not included in constructors cuz itd be too long

	Item();
	Item(int id);
	Item(int id, string name);

};

class InteractiveItem : public Item {
	//for items that do things such as add stat bonuses, or affect the game in other ways than providing additional dialogue options
	//must add in cpp file any additonal content
	int itemBonus;
	bool uniqueItem;

};