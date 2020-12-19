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

void Item::setDescription(string description) {
	descItem = description;
}

Item::Item() {

}

Item::Item(int id) {
	id = id;
}

Item::Item(int id, string name) {
	id = id;
	name = name;
}