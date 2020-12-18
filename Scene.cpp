/*
	File:		Scene.cpp
	Author:		Brandon White
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
	string matchMarker = "#";
	string beatMarker = "@";
	bool sceneFound = false;
	bool sceneDone = false;
	int type = 0;			// 0 = Story, 1 = Base options, 2 = Secret Options
	int secretType = 0;		// 0 = Match or Beat, 1 = Requirement, 2 = Text

	numOptions = 0;
	numStory = 0;
	numSecret = 0;
	
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
			else if (type == 2) {
				// Secret option line!

				if (secretType == 0) {
					// Match or beat!
					if (cpyStr == matchMarker) {
						matchOrBeat[numSecret] = 1;
					}
					else if (cpyStr == beatMarker) {
						matchOrBeat[numSecret] = 0;
					}
					secretType = 1;
				}
				else if (secretType == 1) {
					// Requirement!
					cpyStr.erase(cpyStr.begin());
					secretReqs[numSecret] = stoi(cpyStr);
					secretType = 2;
				}
				else if (secretType == 2) {
					// Text!
					secretOptions[numSecret] = cpyStr;
					numSecret++;
					secretType = 0;
				}
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

int Scene::play(int relevantHist[5]) {

	system("CLS");

	bool validSecret = false;
	int listValidSecrets[5] = { 0, 0, 0, 0, 0 }; 

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

	for (int i = 0; i < numSecret; i++) {
		
		if (matchOrBeat[i] == 0) { // BEAT
			if (relevantHist[i] >= secretReqs[i]) {
				validSecret = true;
			}
		}
		else if (matchOrBeat[i] == 1) { // MATCH
			if (relevantHist[i] == secretReqs[i]) {
				validSecret = true;
			}
		}

		if (validSecret == true) {
			cout << i + 10 << " - " << secretOptions[i] << endl;
			listValidSecrets[i] = i + 10;
		}

		validSecret = false;
	}

// GET ANSWER, CHECK VALIDITY
	while (!isValid) {
		cin >> choice;
	
		if (choice != 0 && ((choice <= numOptions) || choice == listValidSecrets[0] || choice == listValidSecrets[1] || choice == listValidSecrets[2] || choice == listValidSecrets[3] || choice == listValidSecrets[4])) {
			isValid = true;
		}
		else {
			cout << "Invalid choice!" << endl;
		}
	}

// RETURN ANSWER
	return choice;
}