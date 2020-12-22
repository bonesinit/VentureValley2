/*
	File:		Village.cpp
	Author:		Anna Scheidl
*/

#include "Village.h"

void Village::printBuildings(int indexVill, int indexBuild) {

	cout << villageName << endl;

	//if you haven't visited village before, you will get a village decsription.
	//if you have, it won't show up.
	if (visitedVill = false) {
		cout << descType << endl;
	}
	
	cout << "Where would you like to go?" << endl;
	
	for (int x = 0; x <= 5; x++) {
		// print out buildings within the village
		//leaves space to 'delete' a spot if the building is done with/closed.
		if (buildingActive[x]) {
			cout << x << buildings[x] << endl;
			cout << descBuild[x] << endl;
		}
	}
	
	//only allow valid choices
	do {
		cout << "Pick a building above." << endl;
		cin >> indexBuild;
	} while(indexBuild > 5 && indexBuild < 0)

	//call the whereto switch scene statement to move into a building.
	whereTo(int indexBuild);
}

void whereTo(int goChoice) {

	//function that moves to a building.

	switch (goChoice) {
	case 1:
		//go to buildings[0]
		break;
	case 2:
		//go to buildings[1]
		break;
	case 3:
		//go to buildings[2]
		break;
	case 4:
		//go to buildings[3]
		break;
	case 5:
		//go to buildings[4]
		break;
	}
}
