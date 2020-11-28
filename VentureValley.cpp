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
	// Remember: Special options 0 and 1 are character class checks. 2 and 3 are skill checks. 4 is an item/background check.

	// Quest 1: Basement Rats (Test Quest)
	
	Scene* BasementRats_1 = new Scene();
		BasementRats_1->storyLines[0] = "There's a rat in your basement!";
		BasementRats_1->storyLines[1] = "What will you do?";
		BasementRats_1->numStoryLines = 2;
		BasementRats_1->baseOptions[0] = "Run!";
		BasementRats_1->baseOptions[1] = "Hide!";
		BasementRats_1->numBaseOptions = 2;
		BasementRats_1->specialOptions[0] = "[Necromancer] Raise undead rats!";
		BasementRats_1->specialOptions[2] = "[Strength] Punch a rat!";
		BasementRats_1->specialOptions[4] = "[Monkey Friend] Let the monkey deal with it!";
	Scene* BasementRats_1A = new Scene();	// Run!
		BasementRats_1A->storyLines[0] = "Congrats! You ran away! This worked!";
		BasementRats_1A->numStoryLines = 1;
	Scene* BasementRats_1B = new Scene();	// Hide!
		BasementRats_1B->storyLines[0] = "Congrats! You hid! This worked!";
		BasementRats_1B->numStoryLines = 1;
	Scene* BasementRats_1C = new Scene();	// Necromancy
		BasementRats_1C->storyLines[0] = "Congrats! You raised the dead! This worked!";
		BasementRats_1C->numStoryLines = 1;
	Scene* BasementRats_1D = new Scene();	// Punch
		BasementRats_1D->storyLines[0] = "Congrats! You punched a rat! This worked!";
		BasementRats_1D->numStoryLines = 1;
	Scene* BasementRats_1E = new Scene();	// Monkey
		BasementRats_1E->storyLines[0] = "Congrats! You did something with a monkey! This worked!";
		BasementRats_1E->numStoryLines = 1;
	



// SAVED VARIABLES
	int hasMonkeyFriend = 1;


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
				switch (activeQuest) {
				case 1:
					int characterHistory[5];
					characterHistory[0] = 5;		// Class. Would be player->archetype
					characterHistory[1] = 5;		// Class
					characterHistory[3] = 10;		// Strength val. Would be player->stat[0];
					characterHistory[4] = 0;
					characterHistory[5] = hasMonkeyFriend;

					int specialReqs[5] = { 5, 0, 6, 0, 1 };

					int BasementRats_1_Ans = BasementRats_1->play(specialReqs, characterHistory);
					int BasementRats_1A_Ans = 0;
					int BasementRats_1B_Ans = 0;
					int BasementRats_1C_Ans = 0;
					int BasementRats_1D_Ans = 0;
					int BasementRats_1E_Ans = 0;

					switch (BasementRats_1_Ans) {
					case 1: // Run
						// Recycling old stuff from before. Don't do this. 
						BasementRats_1A_Ans = BasementRats_1A->play(specialReqs, characterHistory);
						break;
					case 2: // Hide
						BasementRats_1B_Ans = BasementRats_1B->play(specialReqs, characterHistory);
						break;
					case 6: // Necromancy
						BasementRats_1C_Ans = BasementRats_1C->play(specialReqs, characterHistory);
						break;
					case 8: // Punch
						BasementRats_1D_Ans = BasementRats_1D->play(specialReqs, characterHistory);
						break;
					case 10: // Monkey
						BasementRats_1E_Ans = BasementRats_1E->play(specialReqs, characterHistory);
						break;
					}
					
					

					break;
				}
			}
		}

	}

// CLEAR MEMORY
	delete menu;
	delete BasementRats_1;
	delete BasementRats_1A;
	delete BasementRats_1B;
	delete BasementRats_1C;
	delete BasementRats_1D;
	delete BasementRats_1E;
}
