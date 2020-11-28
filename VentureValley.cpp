#include "TextAdventure.h"

int main()
{
// SETUP MENU
	Menu* menu = new Menu();

// SETUP GAME CONTROL
	bool quit		=	false;	
	bool inGame		=	false;	// If false we are in a menu.
	bool inQuest	=	false;	// If false we are in a village.

	int	menuType	=	1;
	int	menuChoice	=	0;

	int activeQuest =	0;
	int activeVillage = 0;

// SETUP QUESTS
	// Quest 1: Basement Rats (activeQuest == 1)
	// Scene 0
	string bRats_0_story[5] = { "There's rats in your basement!", "What will you do?", " ", " ", " " };
	string bRats_0_options[5] = { "Run!", "Hide!", " ", " ", " " };
	Scene* bRats_0 = new Scene(bRats_0_story, bRats_0_options, 2, 2);
		// Run goes to scene 1, hide goes to scene 2.
	// Scene 1
	string bRats_1_story[5] = { "You ran!", "This worked!", " ", " ", " " };
	string bRats_1_options[5] = { "Yay!", " ", " ", " ", " " };
	Scene* bRats_1 = new Scene(bRats_1_story, bRats_1_options, 2, 1);
	// Scene 2
	string bRats_2_story[5] = { "You hid!", "This worked!", " ", " ", " " };
	string bRats_2_options[5] = { "Yay!", " ", " ", " ", " " };
	Scene* bRats_2 = new Scene(bRats_2_story, bRats_2_options, 2, 1);

	
// SAVED VARIABLES

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
				//menuType = 4;

				// TEMP
				inGame = true;
				inQuest = true;
				activeQuest = 1;
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
			}
		}

		while (inGame) {
			while (!inQuest) {
			
			}

			while (inQuest) {
				
				if (activeQuest == 1) {
					int bRats_0_Ans = bRats_0->play();

					if (bRats_0_Ans == 1) { // Run!
						cout << "Ran away!" << endl;
						int bRats_1_Ans = bRats_1->play();
					}
					else if (bRats_0_Ans == 2) { // Hide!
						cout << "Hidden!" << endl;
						int bRats_2_Ans = bRats_2->play();
					}
				}	
				
			}
		}

	}

// CLEAR MEMORY
	delete menu;
}
