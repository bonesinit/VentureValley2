/*
	File:		Village.cpp
	Author:		Anna Scheidl
*/

#include "Village.h"

void Village::printBuildings(int indexVill, int indexBuild) {

	cout << villageName << endl;
	for (int x = 0; x <= 5; x++) {

		// print out buildings within the village
		if (x == indexBuild) {
			cout << buildings[indexBuild] << endl;
			cout << descBuild[indexBuild] << endl;
		}
	}

}