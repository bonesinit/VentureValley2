/*
	File:		Scene.cpp
	Author:		Brandon White

	None of this works the easy smart way so I need to do it the drawn out dumb way. Please forgive me for my sins.
*/

#include "TextAdventure.h"

Scene::Scene(string story[5], string options[5], int numStory, int numOptions) {
	for (int i = 0; i < 5; i++) {
		this->story[i] = story[i];
		this->options[i] = options[i];
	}

	this->numStory = numStory;
	this->numOptions = numOptions;
}

int Scene::play() {

	system("CLS");

	bool isValid = false;
	int choice;

// PRINT STORY AND OPTIONS

	for (int i = 0; i < numStory; i++) {
		cout << story[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < numOptions; i++) {
		cout << i + 1 << " - " << options[i] << endl;
	}

// GET ANSWER, CHECK VALIDITY
	while (!isValid) {
		cin >> choice;
	
		if (choice != 0 && choice <= numOptions) {
			isValid = true;
		}
		else {
			cout << "Invalid choice!" << endl;
		}
	}

// RETURN ANSWER
	return choice;
}