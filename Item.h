/*
	File:		Item.h
	Author:		Anna Scheidl
*/

#pragma once
using namespace std;
#include <string>

class Item {
	public:
		int id;
		string name;
		string descItem;
		string uniqueToClass[5];
		string notUsedBy[5];

		int cost;

		void printInfo();

};

class InteractiveItem : public Item {

};