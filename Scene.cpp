/*
	File:		Scene.cpp
	Author:		Brandon White

	None of this works the easy smart way so I need to do it the drawn out dumb way. Please forgive me for my sins.
*/

#include "TextAdventure.h"

Scene::Scene() {
	for (int i = 0; i < 5; i++) {
		storyLines[i] = " ";
		baseOptions[i] = " ";
		specialOptions[i] = " ";
	}

	numStoryLines = 0;
	numBaseOptions = 0;
}

int Scene::play(int specialReqs[5], int characterHistory[5]) {

	system("CLS");

	bool isValid = false;
	int choice;
	int validSpecials[5];

// PRINT STORY AND OPTIONS

	for (int i = 0; i < numStoryLines; i++) {
		cout << storyLines[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < numBaseOptions; i++) {
		cout << i + 1 << " - " << baseOptions[i] << endl;
	}

	for (int i = 0; i < 5; i++) {
		if (specialReqs[i] != 0) {
			if (i == 0 || i == 1 || i == 4) {
				if (characterHistory[i] == specialReqs[i]) {
					cout << i + 5 << " - " << specialOptions[i] << endl;
					validSpecials[i] = i + 5;
				}
			}
			else if (i == 2 || i == 3) {
				if (characterHistory[i] >= specialReqs[i]) {
					cout << i + 5 << " - " << specialOptions[i] << endl;
					validSpecials[i] = i + 5;
				}
			}	
		}
	}

// GET ANSWER, CHECK VALIDITY
	while (!isValid) {
		cin >> choice;
	
		if (choice != 0 && choice <= numBaseOptions) {
			isValid = true;
		}
		else if (choice != 0 && choice == validSpecials[0]) {
			isValid = true;
		}
		else if (choice != 0 && choice == validSpecials[1]) {
			isValid = true;
		}
		else if (choice != 0 && choice == validSpecials[2]) {
			isValid = true;
		}
		else if (choice != 0 && choice == validSpecials[3]) {
			isValid = true;
		}
		else if (choice != 0 && choice == validSpecials[4]) {
			isValid = true;
		}	
		else {
			cout << "Invalid choice!" << endl;
		}
	}

// RETURN ANSWER
	return choice;
}