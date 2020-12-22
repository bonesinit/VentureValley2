/*
	File:		Item.cpp
	Author:		Anna Scheidl
*/

#include "Item.h"

void Item::printInfo(int itemIndex) {

	//print item description whether finding it on the quest or at a vendor.

	for (int x = 0; x <= 9; x++) {
		if (itemIndex == id && uniqueToClass[x]) {
			cout << descItem << endl;
		}
	}


};

Item::Item() {

}

Item::Item(int id) {
	id = id;
}

Item::Item(int newId, string newName) {
	id = newId;
	name = newName;
}

Item::Item(int newId, string newName, string description) {
	id = newId;
	name = newName;
	descItem = description;
}