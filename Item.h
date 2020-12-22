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
	int itemBonus;
	bool uniqueItem;
	int cost;

	void printInfo(int itemIndex);

	Item();
	Item(int id);
	Item(int newId, string newName);
	Item(int newId, string newName, string description);

};
