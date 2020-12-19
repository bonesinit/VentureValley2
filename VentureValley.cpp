#pragma once
#include "TextAdventure.h"

int main()
{
// SETUP MENU
	Menu* menu = new Menu();

// SETUP GAME CONTROL
	bool quit			=	false;	
	bool inGame			=	false;	// If false we are in a menu.
	bool inQuest		=	false;	// If false we are in a village.

	int	menuType		=	1;
	int	menuChoice		=	0;

	int activeQuest		=	0;
	int activeVillage	=	0;

// SETUP QUESTS
	// Quest 1: Basement Rats (activeQuest == 1)
	Scene BasementRats[9];
	string BasementRatsFile = "Quests/BasementRats.txt";
	for (int i = 0; i < 9; i++) {
		int sceneNum = i;
		BasementRats[i] = Scene(BasementRatsFile, sceneNum);
	}

// SAVED VARIABLES
	Player player;
	player.id = 0;

// ITEM DATABASE
	Item itemDatabase[50]; //put all premade items here.

	itemDatabase[0] = Item(); //use the desired constructor
	//string testItemDesc = "blah blah w*iner b*lls sw*ar w*rds"
	//itemDatabase[0].setDescription(testItemDesc)

// VENDOR DATABASE
	Vendor vendorDatabase[30]; //put all premade vendors here.

	vendorDatabase[0] = Vendor(); //use the desired constructor

// GAMEPLAY LOOP
	while (!quit) {
		while (!inGame) {
			// See "Menu.h" for documentation.
			menuChoice = menu->printMenu(menuType);

			/* 
				There are 5 menu types:
					1 - Main
					2 - Instructions 
					3 - Pause
					4 - Create character
					5 - Quit
			*/

			switch (menuChoice) {
			// Return to main menu.
			case 0:		
				menuType = 1;
				break;

			// Start a new game.
			case 1:
				menuType = 4;

				// TEMP FOR TESTING QUESTS
				/*
				inGame = true;
				inQuest = true;
				activeQuest = 1;
				*/

				break;
				

			// Load a saved game.
			case 2:
				break;

			// Instructions
			case 3:
				menuType = 2;
				break;
			
			// Quit
			case 9:
				inGame = true;
				quit = true;
				break;

			// Start Game (triggered after char creation)
			case 10:
				inGame = true;
				//activeVillage = 1;

				inQuest = true; //change this to false when villages are implemented
				activeQuest = 1;

				player.name = menu->playerName;
				player.archetype = menu->playerArchetype;
				player.stats[0] = menu->playerStrength;
				player.stats[1] = menu->playerAgility;
				player.stats[2] = menu->playerIntelligence;
				player.stats[3] = menu->playerCharisma;
				player.stats[4] = menu->playerLuck;
				break;
			}

		}

		while (inGame) {
			while (!inQuest) {
			
			}

			while (inQuest) {
				
				// TEMP
				int tempCharHist[5];
				tempCharHist[0] = 7;
				tempCharHist[1] = 1;
				tempCharHist[2] = 0;
				tempCharHist[3] = 0;
				tempCharHist[4] = 0;

				int currScene = 0;
				int ans = 0;

				while (activeQuest == 1) {
					ans = BasementRats[currScene].play(tempCharHist);

					// Scene 0: Rats in your basement!
					if (currScene== 0) {
						switch (ans) {
						case 1:
							currScene = 1;
							break;
						case 2:
							currScene = 2;
							break;
						case 3:
							currScene = 3;
							break;
						case 10: 
							cout << "Secret worked!" << endl;
							system("PAUSE");
							break;
						case 11:
							cout << "Secret worked!" << endl;
							system("PAUSE");
							break;
						}
					}
					// Scene 1: Run in scene 0
					else if (currScene == 1) {
						switch (ans) {
						case 1:
							currScene = 4;
							break;
						case 2:
							currScene = 5;
							break;
						case 3:
							currScene = 8;
							break;
						}
					}
					// Scene 2: Hid in scene 0
					else if (currScene == 2) {
						switch (ans) {
						case 1:
							currScene = 6;
							break;
						case 2:
							currScene = 7;
							break;
						}
					}
					// Scene 3: Fight in scene 0
					else if (currScene == 3) {
						currScene = 8;
					}
					// Scene 4: Buest down door in scene 1
					else if (currScene == 4) {
						currScene = 8;
					}
					// Scene 5: Cried in scene 1
					else if (currScene == 5) {
						activeQuest = 0;
						inQuest = false;
						inGame = false;
					}
					// Scene 6: Didn't question clown in 2
					else if (currScene == 6) {
						currScene = 8;
					}
					// Scene 7: Questioned clown in 2
					else if (currScene == 7) {
						activeQuest = 0;
						inQuest = false;
						inGame = false;
					}
					// Scene 8: Die in 1, 3, 4 or 6
					else if (currScene == 8) {
						activeQuest = 0;
						inQuest = false;
						inGame = false;
					}
				}	
				
			}
		}

	}

// CLEAR MEMORY
	delete menu;
}
