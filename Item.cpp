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

Item::Item(int id, string name) {
	id = id;
	name = name;
}

Item::Item(int id, string name, string description) {
	id = id;
	name = name;
	descItem = description;
}