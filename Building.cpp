/*
	File:		Building.cpp
	Author:		Anna Scheidl

*/

#include "Building.h"

void Building::enterBuilding(int indexBuild) {
	cout << buildingName << endl;

	// Print out the building description + characters residing inside.
	for (int x = 0; x <= 5; x++) {
		if (x == indexBuild) {
			cout << descType << endl;
			for (int x = 0; x <= 3; x++) {
				cout << characterList[x] << endl;
			}
		}
	}

}