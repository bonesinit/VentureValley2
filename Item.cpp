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

