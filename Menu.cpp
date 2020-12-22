/*
	File:		Menu.cpp
	Author:		Brandon White

	See "Menu.h" for documentation.
*/

#include "Menu.h"

int Menu::cinIntMinMax(int toCin, int min, int max) {
	bool valid = false;
	do {
		cin >> toCin;
		if (toCin >= min && toCin <= max)
		{
			valid = true;
			break;
		}
		cout << "Not a valid option!\n";
	} while (!valid);
	playerArchetype = toCin;
	return toCin;
}

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
		//name
		cout << "What is your name, adventurer?" << endl;
		cin >> playerName;
		system("CLS");

		//archetype
		cout << "Alright then " << playerName << ", what kind of adventurer are you?" << endl;
		cout << "0 - Warrior \n1 - Rogue \n2 - Ranger \n3 - Mage \n4 - Bard \n5 - Necromancer \n6 - Shaman / Druid" << endl;
		cinIntMinMax(playerArchetype, 0, 6);
		system("CLS");

		//stats
		cout << "That's a cool class, " << playerName << ". Now it's time to allocate your stats." << endl;
		while (!doneAllocating) {
			statPointsRemaining = maxStatPoints - playerStrength - playerAgility - playerIntelligence - playerCharisma - playerLuck;
			cout << "Current Stats:" << endl;
			cout << "Strength: " << playerStrength << " | Agility: " << playerAgility << " | Intelligence: " << playerIntelligence << " | Charisma: " << playerCharisma << " | Luck: " << playerLuck << endl;
			cout << "Max stat points: " << maxStatPoints << "\nRemaining points to spend: " << statPointsRemaining << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "0 - Change a stat" << endl;
			cout << "1 - Use these stats" << endl;
			cin >> doneAllocating;
			if (doneAllocating == 0)
			{
				system("CLS");
				cout << "Current Stats:" << endl;
				cout << "Strength: " << playerStrength << " | Agility: " << playerAgility << " | Intelligence: " << playerIntelligence << " | Charisma: " << playerCharisma << " | Luck: " << playerLuck << endl;
				cout << "Max stat points: " << maxStatPoints << "\nRemaining points to spend: " << statPointsRemaining << endl;
				cout << "-------------------------------------------------------------" << endl;
				cout << "\n0 - Strength \n1 - Agility \n2 - Intelligence \n3 - Charisma \n4 - Luck" << endl;
				statChoice = cinIntMinMax(statChoice, 0 , 4);
				cout << "Input a number between 1 and 10 for your chosen stat: ";
				if (statChoice == 0) { playerStrength = cinIntMinMax(playerStrength, 1, min(10, statPointsRemaining + 1)); }
				if (statChoice == 1) { playerAgility = cinIntMinMax(playerAgility, 1, min(10, statPointsRemaining + 1)); }
				if (statChoice == 2) { playerIntelligence = cinIntMinMax(playerIntelligence, 1, min(10, statPointsRemaining + 1)); }
				if (statChoice == 3) { playerCharisma = cinIntMinMax(playerCharisma, 1, min(10, statPointsRemaining + 1)); }
				if (statChoice == 4) { playerLuck = cinIntMinMax(playerLuck, 1, min(10, statPointsRemaining + 1)); }
			}
			system("CLS");
		}
		
		cout << "Perfect," << endl;
		cout << "0 - On to adventure!" << endl;
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
		if (type == 4 && choice == 0)				{ valid = true; }	// Char Creation

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

	if (type == 4) {
		choice = 10;
	}

// CLOSE FILES
	menuArt.close();
	instructionsArt.close();

	return choice;
}