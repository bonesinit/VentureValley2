#pragma once
#include "TextAdventure.h"

// This is just for in village stuff.
int getInput(int numOptions, string options[5]);

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
	int activeBuilding	=	0;

// SETUP VILLAGES
	// Village 2: Totenburg
	Village totenburg;
	totenburg.villageName = "Totenburg";
	totenburg.descType = "A big ol' village full of skeletons just trying to get by.";
	totenburg.buildings[0] = "Town Hall";
	totenburg.buildings[1] = "Clack Clack Tavern";
	totenburg.buildings[2] = "Henry's Variety of Goods";
	totenburg.descBuild[0] = "The center of the village's government. Maybe you can get your horse back from there.";
	totenburg.descBuild[1] = "A rough and tumble tavern. Might find a quest there, I dunno.";
	totenburg.descBuild[2] = "Oh boy, I'm sure this place sells a lot of different goods!";
	bool visitedTotenburg = 0;

// SETUP BUILDINGS
	// Village 2: Totenburg
	// TODO LATER
	Building townHall;
	Building clackClack;
	Building henrysVariety;
	bool visitedTownHall = 0;
	bool visitedClackClack = 0;
	bool visitedHenrysVariety = 0;

// SETUP QUESTS
	// Quest 1: Basement Rats (activeQuest == 1)
	Scene BasementRats[9];
	string BasementRatsFile = "Quests/BasementRats.txt";
	for (int i = 0; i < 9; i++) {
		int sceneNum = i;
		BasementRats[i] = Scene(BasementRatsFile, sceneNum);
	}

	// Test Quest 2: Dellhollow Intro (activeQuest == 2). feel free to bump this quest back a bunch if you want yours to be consecutive.
	Scene DellhollowIntro[2];
	string DellhollowIntroFile = "Quests/JoshTestQuest.txt";
	for (int i = 0; i < 2; i++) {
		int sceneNum = i;
		DellhollowIntro[i] = Scene(DellhollowIntroFile, sceneNum);
	}

	// Quest 3: Milk Man (activeQuest == 3) Totenburg side quest
	Scene MilkMan[25];
	string MilkManFile = "Quests/MilkMan.txt";
	for (int i = 0; i < 25; i++) {
		int sceneNum = i;
		MilkMan[i] = Scene(MilkManFile, sceneNum);
	}

// SAVED VARIABLES
	Player player;
	player.id = 0;

	int mayoralMishapsOutcome = 0;
	int sharkHunterOutcome = 0;
	int milkManOutcome = 0;

// ITEM DATABASE
	Item itemDatabase[30]; //put all premade items here. see Item.h for constructor documentation.
	
	itemDatabase[20] = Item(20, "Banana", "A long yellow thing. The mankeys love it!");
	itemDatabase[21] = Item(21, "Suspicious Banana", "A long yellow thing. The mankeys love it!");

// VENDOR DATABASE
	Vendor vendorDatabase[30]; //put all premade vendors here. see Character.h for constructor documentation.

	vendorDatabase[20] = Vendor(20, "Phil", itemDatabase[20]); //Phil will be a banana vendor in Dellhollow.
	vendorDatabase[21] = Vendor(21, "Morrissey", itemDatabase[21]); //Morrissey will be black market dealer in Dellhollow available to rogues.

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
				activeVillage = 2;
				activeBuilding = 0;

				inQuest = false; //change this to false when villages are implemented
				activeQuest = 0;

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
				system("CLS");

				// Village 2: Totenburg
				while (activeVillage == 2) {
					system("CLS");

					// In the main village!
					if (activeBuilding == 0) {
						// First visit gives you special story!
						if (visitedTotenburg == 0) {

							cout << "As you near Totenburg on your horse you hear what sounds like a hundred rhythmless xylophones in the distance." << endl;
							cout << "You've heard the rumors about the coastal village, but it just seemed so ridiculous at the time." << endl;
							cout << "But nope, when you reach town your two eyes confirm that Totenburg is indeed a town entirely populated by skeletons." << endl;
							cout << endl;
							cout << "Despite the fact everyone is dead, the town seems pretty lively." << endl;
							cout << "Skeletons are going about their daily errands but your \"flesh suit\" is turning some heads." << endl;
							cout << endl;
							cout << "A guard approaches you. His jaw flaps comically as he talks." << endl;
							cout << "The guard tells you he'll have to confiscate your horse." << endl;
							cout << "You start to protest but he pulls the horse out from under you and runs off, holding it over his head with ease." << endl;
							cout << "He yells that if you want it back you'll have to go to town hall, and he disappears into the distance." << endl;
							cout << endl;
							cout << "Well it looks like you're stuck here. " << endl;
							cout << endl;

							visitedTotenburg = 1;
						}

						// TEMP
						cout << "Where do you want to go?" << endl;
						string tBuildingOptions[5] = { "Town Hall", "Clack Clack Tavern", "Henry's Variety of Goods", " ", " " };
						activeBuilding = getInput(3, tBuildingOptions);
					}

					// Town Hall
					if (activeBuilding == 1) {
						system("CLS");
						cout << "Sorry, town hall's closed!" << endl;
						system("PAUSE");
						activeBuilding = 0;
						// First visit
						if (visitedTownHall == 0) {

							visitedTownHall = 1;
						}

						// Rejected quest, visiting again
						else if (visitedTownHall == 1 && mayoralMishapsOutcome == 0) {

						}

						// Visiting after quest complete
						else {

						}
					}

					// Clack Clack Tavern
					if (activeBuilding == 2) {
						system("CLS");
						cout << "Sorry, tavern's closed!" << endl;
						system("PAUSE");
						activeBuilding = 0;
						if (visitedClackClack == 0) {

						}

						else if (visitedClackClack == 1 && sharkHunterOutcome == 0) {

						}

						else {

						}
					}

					// Henry's Variety
					if (activeBuilding == 3) {

						system("CLS");

						if (visitedHenrysVariety == 0) {
							cout << "You open the door to Henry's Variety of Goods and step inside." << endl;
							cout << "It's totally empty, except for a small counter with a glass on it and a big keg labelled \"Milk\" with a tap on it." << endl;
							cout << "Someone in a dark cloak is standing at the counter.You can't see their face, but you presume it's Henry." << endl;
							cout << "He asks you to come in, in a wispy spooky voice of course." << endl;
							cout << endl;
							cout << "You walk up to the counter." << endl;
							cout << "He asks you what he can do for you." << endl;
							cout << "You ask him what he has for sale." << endl;
							cout << "He slaps the top of the barrel and points to the glass." << endl;
							cout << endl;
							cout << "It appears he only sells milk." << endl;
							cout << endl;

							cout << "Do you... wanna buy some milk?" << endl;
							cout << endl;
							string milkOptions[5] = {"Yes", "No", " ", " ", " " };
							int boughtMilk = getInput(2, milkOptions);

							system("CLS");

							// Bought Milk
							if (boughtMilk == 1) {
								cout << "You give him a coin and he pours your glass of milk." << endl;
								cout << "You take a sip and tell him it taste like someone crushed up white chalk and mixed it with water." << endl;
								cout << "He puts his head in his hands and begins to sob." << endl;
								cout << "He tells you all about how someone in town made off with his cow and now his business is failing." << endl;
								cout << "He doesn't know who to trust anymore and asks you if you can help." << endl;
								cout << endl;

								string milkManOptions[5] = { "[Start Quest] Yeah sure why not." , "Nah I have better things to do.", " ", " ", " " };
								int milkManStarted = getInput(2, milkManOptions);

								system("CLS");

								if (milkManStarted == 1) {
									activeBuilding = 0;
									activeVillage = 0;
									inQuest = 1;
									activeQuest = 3;
								}

								else if (milkManStarted == 2) {
									cout << "He sniffles and tells you that if you change your mind you should come back." << endl;
									cout << "He says he would really appreciate it and probably give you something good." << endl;
									cout << "Even though you're a heartless monster." << endl;
									cout << "WHO DOESN'T EVEN CARE ABOUT A MAN AND HIS COW" << endl;
									cout << endl;

									system("PAUSE");
									activeBuilding = 0;
								}
							}

							// Didn't buy milk.
							else if (boughtMilk == 2) {
								cout << "He just kind of shrugs and goes quiet. Some variety they have here." << endl;
								cout << endl;
								string noMilkOptions[5] = { "Get out of here.", " ", " ", " ", " "};
								int noMilkInput = getInput(1, noMilkOptions);
								activeBuilding = 0;
							}

							visitedHenrysVariety = 1;
						}

						else if (visitedHenrysVariety == 1 && milkManOutcome == 0) {
							cout << "\"Are you here to help me with my cow?\"" << endl;
							cout << endl;
							string milkManOptions[5] = { "[Start Quest] Yeah sure why not." , "Nah I have better things to do.", " ", " ", " " };
							int milkManStarted = getInput(2, milkManOptions);

							if (milkManStarted == 1) {
								activeBuilding = 0;
								activeVillage = 0;
								inQuest = 1;
								activeQuest = 3;
							}

							else if (milkManStarted == 2) {
								activeBuilding = 0;
							}
						}

						else {
							cout << "\"Thanks again for helping me with my cow problem!\"" << endl;
							cout << "\"Here's some milk on the house!\"" << endl;
							cout << endl;
							system("PAUSE");
							activeBuilding = 0;
						}
					}

				}

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

				// Basement Rats
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

				while (activeQuest == 2) {
					ans = DellhollowIntro[currScene].play(tempCharHist);

					// Scene 0: intro
					if (currScene == 0) {
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
							currScene = 4;
							break;
						case 11:
							currScene = 5;
							break;
						}
					}
					// Scene 1: Bribed in scene 0.
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
					// Scene 2: Waited a few days in scene 0.
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
				}
				
				int charHistMilkMan[5];
				int receiptsFound = 0;
				// Milk Man
				while (activeQuest == 3) {
					if (currScene == 24) {
						cout << "This is the end of the demo! Thanks for playing!" << endl;
						system("PAUSE");
					}

					ans = MilkMan[currScene].play(charHistMilkMan);
					
					// Start
					if (currScene == 0) {
						switch (ans) {
						// Tell me about Bart
						case 1:	
							currScene = 1;
							break;
						// Tell me about Rudolf
						case 2:
							currScene = 2;
							break;
						// Visit Bart
						case 3:
							currScene = 3;
							// Setup for next scene
							charHistMilkMan[0] = player.stats[3]; // charisma
							charHistMilkMan[1] = player.archetype; // class
							break;
						// Visit Rudolf
						case 4:
							charHistMilkMan[0] = receiptsFound;
							currScene = 14;
							break;
						}
					}
					// Ask about Bart/Rudolf
					else if (currScene == 1 || currScene == 2) {
						currScene = 0;
					}
				// BART PLOTLINE
					// Visit Bart
					else if (currScene == 3) {
						switch (ans) {
						// Ask Bart about cow
						case 1:
							currScene = 4;
							break;
						// Violently ask Bart
						case 2: 
							currScene = 5;
							charHistMilkMan[0] = player.stats[0]; // Strength
							break;
						// Sneak into Bart's place
						case 3:
							currScene = 9;
							charHistMilkMan[0] = player.stats[4]; // Luck
							break;
						// [Charisma] Sweet talk bart
						case 10: 
							currScene = 11;
							receiptsFound++;
							break;
						// Bard Rock bart
						case 11: 
							currScene = 12;
							receiptsFound++;
							break;
						}
					}
					// Ask Bart
					else if (currScene == 4 || currScene == 6) {
						charHistMilkMan[0] = player.stats[3]; // charisma
						charHistMilkMan[1] = player.archetype; // class
						currScene = 3;
					}
					// Violently ask Bart
					else if (currScene == 5) {
						switch (ans) {
						// Slap duck
						case 1:
							currScene = 6;
							break;
						// Stab
						case 2:
							currScene = 7;
							receiptsFound++;
							break;
						// Strength
						case 10: 
							currScene = 8;
							receiptsFound++;
							break;
						}
					}
					// Got reciept, go back to Henry
					else if ((currScene == 7 || currScene == 8 || currScene == 10 || currScene == 11 || currScene == 12) && receiptsFound == 1) {
						currScene = 13;
					}
					else if (currScene == 9) {
						switch (ans) {
						case 1:
							currScene = 3;
							break;
						case 10:
							currScene = 10;
							receiptsFound++;
							break;
						}
					}
					// Only Barts receipt, talk to Henry.
					else if (currScene == 13) {
						charHistMilkMan[0] = receiptsFound;
						currScene = 14;
					}
				// RUDOLF PLOTLINE
					// Visit Rudolf
					else if (currScene == 14) {
						switch (ans) {
						case 1:
							currScene = 15;
							break;
						case 2:
							currScene = 16;
							break;
						case 3:
							charHistMilkMan[0] = player.archetype;
							currScene = 17;
							break;
						case 11:
							currScene = 22;
							break;
						}
					}
					// Messed up
					else if (currScene == 15 || currScene == 16 || currScene == 20) {
						charHistMilkMan[0] = receiptsFound;
						currScene = 14;
					}
					// Chimney
					else if (currScene == 17) {
						switch (ans) {
						case 1:
							currScene = 18;
							break;
						case 2:
							currScene = 20;
							break;
						case 10:
							currScene = 21;
							receiptsFound++;
							break;
						}
					}	
					else if (currScene == 18) {
						currScene = 19;
						receiptsFound++;
					}
					// Got receipt 1/2
					else if ((currScene == 19 || currScene == 21 || currScene == 22 || currScene == 21) && receiptsFound == 1) {
						currScene = 23;
					}
					// Got receipt 2/2
					else if (receiptsFound == 2) {
						currScene = 24;
					}
					else if (currScene == 23) {
						charHistMilkMan[0] = player.stats[3]; // charisma
						charHistMilkMan[1] = player.archetype; // class
						currScene = 3;
					}
					else if (currScene == 24) {
						cout << "Congrats on completing our demo!" << endl;
						cout << "Please close the game or it will explode!" << endl;
						system("PAUSE");
					}
				}
				
			}
		}

	}

// CLEAR MEMORY
	delete menu;
}

int getInput(int numOptions, string options[5]) {
	for (int i = 0; i < numOptions; i++) {
		cout << i + 1 << " - " << options[i] << endl;
	}
	cout << endl;

	int input;
	bool validInput = false;

	while (validInput == false) {
		cin >> input;

		if (input >= 1 && input <= numOptions) {
			validInput = true;
		}
		else {
			cout << "Not an option!" << endl;
		}
	}

	return input;
}