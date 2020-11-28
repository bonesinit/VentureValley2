/*
	File:		Menu.cpp
	Author:		Brandon White

	See "Menu.h" for documentation.
*/

#include "Menu.h"

int Menu::printMenu(int type) {
	
	ifstream	menuArt("Files/MenuArt.txt");
	string		menuArtString;

	ifstream	instructionsArt("Files/Instructions.txt");
	string		instructionsArtString;

	bool valid = false;

	int choice;	
	/* 
		Choices get converted in the end. Here's all of the true choices.
			0 - Return to main menu. 
			1 - Start a new game
			2 - Load a saved game.
			3 - How to play.
			9 - Quit
	*/

	system("CLS");

// MENUS
	switch (type) {

	// Main Menu
	case 1:
		while (getline(menuArt, menuArtString)) {
			cout << menuArtString << endl;
		}		

		cout <<	"\n1 - Start a new game." << endl;
		cout <<	"2 - Load a saved game." << endl;
		cout << "3 - How to play." << endl;
		cout << "4 - Quit." << endl;

		break;

	// Instructions
	case 2:
		while (getline(instructionsArt, instructionsArtString)) {
			cout << instructionsArtString << endl;
		}
		
		cout << "\n1 - Return to main menu." << endl;

		break;

	// Pause
	case 3:

		break;

	// Create Character 
	case 4:

		break;
		
	// Quit
	case 5:
		cout << "Are you sure you want to quit?" << endl;

		cout << "\n1 - Yes" << endl;
		cout << "2 - No" << endl;
		break;
	}

// CHECK VALIDITY
	while (!valid) {
		cin >> choice;

		if (type == 1 && choice > 0 && choice <= 4) { valid = true; }	// Main
		if (type == 2 && choice == 1)				{ valid = true; }	// Instructions
		if (type == 5 && choice > 0 && choice <= 2) { valid = true; }	// Quit

		if (!valid) {
			cout << "Not a valid option!" << endl;
		}
	}

// CHOICE CONVERSION
	// Converts choice into menuType for use in main.
	if (type == 1 && choice == 4) {
		choice = 9;
	}

	if (type == 2) {
		choice = 0;
	}

	if (type == 5) {
		if (choice == 1) { choice = 9; }	// Quit
		if (choice == 2) { choice = 0; }	// Return to main menu.
	}

// CLOSE FILES
	menuArt.close();
	instructionsArt.close();

	return choice;
}