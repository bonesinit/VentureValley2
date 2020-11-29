/*
	File:		Scene.cpp
	Author:		Brandon White

	None of this works the easy smart way so I need to do it the drawn out dumb way. Please forgive me for my sins.
*/

#include "TextAdventure.h"

// Default constructor initializes everything and sets it to zero.
Scene::Scene() {
	for (int i = 0; i < 5; i++) {
		story[i] = " ";
		options[i] = " ";
	}

	numStory = 0;
	numOptions = 0;
}

// Auto constructor can be used to set multiple scenes at once
Scene::Scene(string fileLocation, int sceneNum) {
	ifstream	questFile(fileLocation);
	string		cpyStr; 

	string sSceneNum = to_string(sceneNum);
	string changeMarker = "!";
	string endMarker = "?";
	bool sceneFound = false;
	bool sceneDone = false;
	int type = 0;

	numOptions = 0;
	numStory = 0;
	
	while ((getline(questFile, cpyStr)) && (sceneDone == false)) {
		if ((sceneFound == true) && (cpyStr == endMarker)) {
			// Found an end marker after the scene! We're done!
			sceneDone = true;
		}

		if ((sceneFound == false) && (sSceneNum == cpyStr)) {
			// We're at the start of a scene!
			sceneFound = true;
		}

		if ((sceneFound == true) && (cpyStr == changeMarker)) {
			// Hit a change marker! This changes where we write lines to!
			type++;
		}

		if ((sceneFound == true) && (cpyStr != changeMarker) && (cpyStr != sSceneNum) && (cpyStr != endMarker)) {
			// We found a line! lets print it!
			if (type == 0) {	
				// Story line!
				story[numStory] = cpyStr;
				numStory++;

			}
			else if (type == 1) {	
				// Option line!
				options[numOptions] = cpyStr;
				numOptions++;
			}
		}
	}

	questFile.close();
}

// Manual constructor can be used to set one scene at a time.
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