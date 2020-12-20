/*
	File:		Village.h
	Author:		Anna Scheidl
*/

#pragma once
using namespace std;
#include <string>
#include <iostream>

class Village {
public:
	string villageName;
	string descType;


	/*  The first village, Ptelios, created by Anna: Town with an ancient temple. The villagers worship the sun god Helios. They are known for their ancient hero, Pete.
		The second village, Totenburg, created by Brandon: A town of skeletons trying to elect a new mayor.
		The third village, Dellhollow, created by Joshua: An impoverished and crime - stricken coastal village that’s been placed under a horrible curse where
															everyone has been turned into monkeys.
	*/

	string buildings[5];
	string descBuild[5];
	/* Example:
		1 - Blacksmith
		2 - Town Hall
		3 - General Store
		4 - Temple
		5 - Inn
	*/

	void printBuildings(int indexVill, int indexBuild);

};
