#pragma once
#include "TextAdventure.h"

// This is just for in village stuff.
int getInput(int numOptions, string options[5]);

void saveGame(Player player);

Player loadGame();

Item itemDatabase[50];
Vendor vendorDatabase[30];

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
	/*
	// Village 1: Ptelios

	Village ptelios;
	ptelios.villageName = "Ptelios";
	ptelios.visitedVill = false;
	ptelios.descType = "Town with an ancient temple. The villagers worship the sun god Helios. They are known for their ancient hero, Pete.";
	ptelios.buildings[0] = "Blacksmith";
	ptelios.buildings[1] = "Town Hall";
	ptelios.buildings[2] = "General Store";
	ptelios.buildings[3] = "Temple";
	ptelios.buildings[4] = "Inn";
	ptelios.descBuild[0] = "A heavy clang bursts through the village chatter. You know you would find any armoured goods if you were to enter.";
	ptelios.descBuild[1] = "Guards stand on either side of the large wooden doors. This extra bit of security tells you that someone important is inside. You would find the mayor here.";
	ptelios.descBuild[2] = "The familiar sign of the trademarked good store sends a warmth through you. You know you would find material goods you needed there.";
	ptelios.descBuild[3] = "At the very centre of the town stands a large ancient temple. Villagers filter in and out of it in silence. Faces of the village hero, Pete stare at you from where gargoyles would be.";
	ptelios.descBuild[4] = "The sweet aroma of warm food fills your nostrils while the jovial laughter of tavern-goers meets your ears. You can tell that you would find many villagers frequenting the place.";
	ptelios.buildingActive[0] = true;
	ptelios.buildingActive[1] = true;
	ptelios.buildingActive[2] = true;
	ptelios.buildingActive[3] = true;
	ptelios.buildingActive[4] = true;
	*/
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
	/*
	//Village 1: Ptelios
	Building blacksmith;
	Building townBuild;
	Building generalStore;
	Building temple;
	Building inn;
	blacksmith.visitedBuild = false;
	blacksmith.descType = "As you enter, a burly figure is leaning over an anvil hammering out the edge of a blade. A young boy watches, eager to learn the craft. On the other end stands a customer who is looking at the various weapon displays.";
	townBuild.visitedBuild = false;
	townBuild.descType = "The guards open the doors for you, and you see a large hall with a chair at the end. A man sits at it, listening to a villager. At his side is a scribe and an advisor.";
	generalStore.visitedBuild = false;
	generalStore.descType = "You find the store to be very welcoming, the warm light shining on the pale yellow and white bricked walls. You see the store manager behind the counter, chatting amiably with a mother and their child.";
	temple.visitedBuild = false;
	temple.descType = "As you enter, you are encapsulated in silence. Everytime you think of speaking, you find your throat is dry. You see someone praying in a pew. At the front is a tall statue of a person surrounded by a large sun. You can see a few priestess reading from a text.";
	inn.visitedBuild = false;
	inn.descType = "When you enter the inn, you are met with warm air and raucous laughter. Someone throws their arm around you and cheers while others thump you on the back in greeting. Many people are gathered here, and you can see a bartender making drinks behind their bar.";
	*/

	// Village 2: Totenburg
	// TODO LATER
	Building townHall;
	Building clackClack;
	Building henrysVariety;
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

	// Quest 3: Milk Man (activeQuest == 3) Totenburg main quest
	Scene MilkMan[40];
	string MilkManFile = "Quests/MilkMan.txt";
	for (int i = 0; i < 40; i++) {
		int sceneNum = i;
		MilkMan[i] = Scene(MilkManFile, sceneNum);
	}

	// Quest 4: Mayoral Mishaps
	Scene MayoralMishaps[6];
	string MayoralMishapsFile = "Quests/MayoralMishaps.txt";
	for (int i = 0; i < 6; i++) {
		int sceneNum = i;
		MayoralMishaps[i] = Scene(MayoralMishapsFile, sceneNum);
	}

	// Quest 5: Shark Hunter
	Scene SharkHunter[8];
	string SharkHunterFile = "Quests/SharkHunter.txt";
	for (int i = 0; i < 8; i++) {
		int sceneNum = i;
		SharkHunter[i] = Scene(SharkHunterFile, sceneNum);
	}
// ITEM DATABASE
	itemDatabase[0] = Item(0, "Empty", "Empty inventory slot");
	itemDatabase[20] = Item(20, "Banana", "A long yellow thing. The mankeys love it!");
	itemDatabase[21] = Item(21, "Suspicious Banana", "A long yellow thing. The mankeys love it!");

// VENDOR DATABASE
	vendorDatabase[20] = Vendor(20, "Phil", itemDatabase[20]); //Phil will be a banana vendor in Dellhollow.
	vendorDatabase[21] = Vendor(21, "Morrissey", itemDatabase[21]); //Morrissey will be black market dealer in Dellhollow available to rogues.

// SAVED VARIABLES
	Player player;
	player.id = 0;
	for (int i = 0; i < 5; i++) {
		player.inventory[i] = itemDatabase[0];
	}
	

	int mayoralMishapsOutcome = 0;
	int sharkHunterOutcome = 0;
	int milkManOutcome = 0;
	
	int fireworks = 0;
	int speedrunWand = 0;
	int poison = 0;
	int bigRock = 0;
	int kickingBoots = 0;
	int bartReceipt = 0;
	int rudolfReceipt = 0;


// ITEM DATABASE
	Item itemDatabase[30]; //put all premade items here. see Item.h for constructor documentation.
	
	//Ptelios
	itemDatabase[10] = Item(10, "Chainmail Armour", "The best armour on the market. No death-free guarantee. Warranty-free!");
	itemDatabase[11] = Item(11, "Coffee", "Not high-end, but enough to get you going in the morning. No death-free guarantee.");
	itemDatabase[12] = Item(12, "Slippery Slope Pint", "After a long day, it's nice to relax. Strongest alcohol in the village. No death-free guarantee.");
	itemDatabase[13] = Item(13, "Scroll", "The scroll reads, after some translation: The fourth stone on the eastern wall, six feet to the bone you must crawl.");
	itemDatabase[14] = Item(14, "Candles", "Multiple sets of candles to light up the temple.");
	
	itemDatabase[20] = Item(20, "Banana", "A long yellow thing. The mankeys love it!");
	itemDatabase[21] = Item(21, "Suspicious Banana", "A long yellow thing. The mankeys love it!");

// VENDOR DATABASE
	Vendor vendorDatabase[30]; //put all premade vendors here. see Character.h for constructor documentation.
	
	//Ptelios
	vendorDatabase[10] = Vendor(10, "Farley", itemDatabase[10]); //he has special armour he is making.
	vendorDatabase[11] = Vendor(11, "Jarson", itemDatabase[11]); //he sells all sorts of items at the general goods store
	vendorDatabase[12] = Vendor(12, "Polly", itemDatabase[12]); //if you need a drink after a long day, she's your gal.


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
				player = loadGame();
				inGame = true;
				activeVillage = 2;
				activeBuilding = 0;

				inQuest = false; //change this to false when villages are implemented
				activeQuest = 0;
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

						if (mayoralMishapsOutcome == 0) {
							cout << "You arrive at town hall and you meet two arguing skeletons. They introduce themselves as" << endl;
							cout << "P. Bone Simmons and G. Scapulas Murphy. They introduce themselves as the vilage's two mayoral candidates" << endl;
							cout << "since the old mayor died 362 years ago. The death was very unexpected and there's never actually been" << endl;
							cout << "an election before since the old mayor was actually a warlord." << endl;
							cout << "You ask about your horse, and they tell you horses weren't invented until 361 years ago, so by the default" << endl;
							cout << "of the old laws horses are contraband." << endl;
							cout << endl;

							string townHallOptions[5] = { "[Start Quest] Help them solve their problem." , "Leave.", " ", " ", " " };
							int townHallChoice = getInput(2, townHallOptions);

							if (townHallChoice == 1) {
								activeBuilding = 0;
								activeVillage = 0;
								inQuest = 1;
								activeQuest = 4;
							}
							else if (townHallChoice == 2) {
								activeBuilding = 0;
							}
						}
						else if (mayoralMishapsOutcome > 0) {
							cout << "\"Thanks for your help!\" says the mayor." << endl;
							system("PAUSE");
							activeBuilding = 0;
						}
					}

					// Clack Clack Tavern
					if (activeBuilding == 2) {
						system("CLS");
						
						cout << "You enter the tavern. It's a rough and tumble place." << endl;
						cout << "To your left, there's a couple skeletons brawling. One gets his head punched off, puts it back on, and punches off the other guys head." << endl;
						cout << "They just keep doing that. Nobody seems to care. Maybe thev're been at it for a while." << endl;
						cout << "To your right is a bard playing a lute. He's actually pretty good." << endl;
						cout << "Ahead of you is a bartender. She has a hook hand and two eye patches." << endl;
						cout << "On her tunic is a pin that says \"Don't ask\"." << endl;
						cout << "You walk up to her and she asks you what you want." << endl;
						cout << endl;
						string clackClackOptions[5] = { "[Start Quest] A quest!", "To leave.", " ", " ", " " };
						int clackClackChoice = getInput(2, clackClackOptions);

						if (clackClackChoice == 1) {
							activeBuilding = 0;
							activeVillage = 0;
							inQuest = 1;
							activeQuest = 5;
						}
						else if (clackClackChoice == 2) {
							activeBuilding = 0;
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

					// Save Game
					if (activeBuilding == 4) {
						cout << "player: " << player.inventory[0].name << endl;
						cout << "database: " << itemDatabase[0].name << endl;
						system("PAUSE");
						saveGame(player);
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
				// Milk Man
				while (activeQuest == 3) {
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
							charHistMilkMan[0] = bartReceipt;
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
							fireworks = 1;
							bartReceipt = 1;
							break;
						// Bard Rock bart
						case 11: 
							currScene = 12;
							bartReceipt = 1;
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
							bartReceipt = 1;
							break;
						// Strength
						case 10: 
							currScene = 8;
							bartReceipt = 1;
							break;
						}
					}
					// Got reciept, go back to Henry
					else if ((currScene == 7 || currScene == 8 || currScene == 10 || currScene == 11 || currScene == 12) && bartReceipt == 1 && rudolfReceipt == 0) {
						currScene = 13;
					}
					else if (currScene == 9) {
						switch (ans) {
						case 1:
							currScene = 3;
							break;
						case 10:
							currScene = 10;
							fireworks = 1;
							bartReceipt = 1;
							break;
						}
					}
					// Only Barts receipt, talk to Henry.
					else if (currScene == 13) {
						charHistMilkMan[0] = bartReceipt;
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
						case 10:
							rudolfReceipt = 1;
							currScene = 22;
							break;
						}
					}
					// Messed up
					else if (currScene == 15 || currScene == 16 || currScene == 20) {
						charHistMilkMan[0] = bartReceipt;
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
							rudolfReceipt = 1;
							break;
						}
					}	
					else if (currScene == 18) {
						currScene = 19;
						rudolfReceipt = 1;
					}
					// Got receipt 1/2
					else if ((currScene == 19 || currScene == 21 || currScene == 22 || currScene == 21)) {
						if (rudolfReceipt == 1 && bartReceipt == 1) {
							currScene = 24;
						}
						else {
							currScene = 23;
						}
					}
					else if (currScene == 23) {
						charHistMilkMan[0] = player.stats[3]; // charisma
						charHistMilkMan[1] = player.archetype; // class
						currScene = 3;
					}
					else if (currScene == 24) {
						charHistMilkMan[0] = fireworks;
						currScene = 25;
					}
				// RESCUE THE COW!!!
					// First choice at mausoleum
					else if (currScene == 25) {
						switch (ans) {
						case 1:
							currScene = 26;
							break;
						case 2:
							currScene = 31;
							break;
						case 10:
							currScene = 32;
							break;
						}
					} 
					// Create a commotion
					else if (currScene == 26) {
						switch (ans) {
						case 1:
							currScene = 27;
							break;
						case 2:
							currScene = 28;
							break;
						}
					}
					// Yell
					else if (currScene == 27) {
						switch (ans) {
						case 1:
							charHistMilkMan[0] = player.archetype;
							charHistMilkMan[1] = player.stats[2];
							charHistMilkMan[3] = bigRock;
							break;
						case 2:
							currScene = 30;
							break;
						}
					}
					// Bang on door
					else if (currScene == 28) {
						currScene = 25;
					}
					// Headed into mausoleum, fight/talk
					else if (currScene == 29) {
						switch (ans) {
						case 1:
							currScene = 33;
							break;
						case 2:
							currScene = 34;
							break;
						case 10:
							currScene = 35;
							break;
						case 11:
							currScene = 36;
							break;
						case 12:
							currScene = 37;
							break;
						}
					}
					// Keep being insane
					else if (currScene == 30) {
						bigRock = 1;
						currScene = 29;
					}
					// Fail to break in
					else if (currScene == 31) {
						currScene = 25;
					}
					// Blow it up!
					else if (currScene == 32) {
						currScene = 39;
					}
					// Fail at talking him down
					else if (currScene == 33) {
					currScene = 35;
					}
					// Beat him up
					else if (currScene == 34) {
						currScene = 38;
					}
					// Raise undead army, convince him this is dumb, hit him with big rock
					else if (currScene == 35 || currScene == 36 || currScene == 37) {
						currScene = 39;
					}
					// Reward for half a cow
					else if (currScene == 38) {
						milkManOutcome = 1;
						kickingBoots = 1;
						activeVillage = 2;
						activeQuest = 0;
						inQuest = false;
					}
					// Reward for full cow
					else if (currScene == 38) {
						milkManOutcome = 2;
						kickingBoots = 1;
						speedrunWand = 1;
						activeVillage = 2;
						activeQuest = 0;
						inQuest = false;
					}
				}
				
				int charHistMayoralMishaps[5];
				// Mayoral Mishaps
				while (activeQuest == 4) {

					charHistMayoralMishaps[0] = speedrunWand;
					ans = MayoralMishaps[currScene].play(charHistMayoralMishaps);

					if (currScene == 0) {
						switch (ans) {
						case 1:
							currScene = 1;
							break;
						case 2:
							currScene = 2;
							break;
						case 10:
							currScene = 3;
							break;
						}
					}
					else if (currScene == 1 || currScene == 2) {
						switch (ans) {
						case 1:
							currScene = 4;
							break;
						case 2:
							currScene = 5;
							break;
						}
					}
					else if (currScene == 3 || currScene == 4 || currScene == 5) {
						if (currScene == 3) {
							poison = 1;
						}
						activeVillage = 2;
						activeQuest = 0;
						inQuest = false;
						mayoralMishapsOutcome = 1;
					}
				}

				int charHistSharkHunter[5];
				// Shark Hunter
				while (activeQuest == 5) {
					charHistSharkHunter[0] = player.stats[2];
					charHistSharkHunter[1] = poison;

					ans = SharkHunter[currScene].play(charHistSharkHunter);

					if (currScene == 0) {
						switch (ans) {
						case 1: 
							currScene = 2;
							break;
						case 2:
							currScene = 1;
						}
					}
					else if (currScene == 1) {
						currScene = 0;
					}
					else if (currScene == 2) {
						switch (ans) {
						case 1:
							currScene = 3;
							break;
						case 2:
							currScene = 4;
							break;
						case 3:
							currScene = 5;
							break;
						}
					}
					else if (currScene == 4) {
						currScene = 6;
						
					}
					else if (currScene == 5 || currScene == 3) {
						currScene = 7;
					}
					else if (currScene == 6) {
						activeVillage = 2;
						activeQuest = 0;
						inQuest = false;
						sharkHunterOutcome = 1;
					}
					else if (currScene == 7) {
						activeVillage = 2;
						activeQuest = 0;
						inQuest = false;
						sharkHunterOutcome = 2;
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

void saveGame(Player player) {

	//Open file
	ofstream saveDataTxt("saveData.txt", ios::trunc); //opens file, makes one if the filename doesn't exist
	//saveDataTxt.open("saveData.txt");

	if (saveDataTxt.is_open()) {
		//Name
		saveDataTxt << "Name: " << player.name << "\n";

		//Archetype
		saveDataTxt << "Archetype ID: " << player.archetype << "\n";

		//Stats
		saveDataTxt << "Stats: ";
		for (int i = 0; i < 5; i++)
		{
			saveDataTxt << player.stats[i];
			saveDataTxt << " ";
		}
		saveDataTxt << "\n";

		//Items
		saveDataTxt << "Item IDs: ";
		for (int i = 0; i < 5; i++)
		{
			saveDataTxt << player.getItemID(i);
			saveDataTxt << " ";
		}
		saveDataTxt << "\n";

		//Current Village


		//Confirmation message
		cout << "Game has been saved!" << endl;

		//close file
		saveDataTxt.close();

		system("PAUSE");
		system("CLS");
	}
	else {
		cout << "Failed to open file!" << endl;
	}

}

Player loadGame() {
	Player newPlayer;
	string line;
	char startReadMarker = ':';
	ifstream saveDataTxt("saveData.txt"); //opens file, makes one if the filename doesn't exist
	
	string nameToLoad = " ";
	int archetypeToLoad = 0;
	int statsToLoad[5] = { 1,1,1,1,1 };
	int itemIdsToLoad[5] = { 0,0,0,0,0 };

	if (saveDataTxt.is_open()) {
		cout << "Opened save file!" << endl;

		//NAME
		getline(saveDataTxt, line);
		for (int i = 0; i < line.size(); i++) {
			if (line.at(i) == startReadMarker)
			{
				int s = 0;
				for (int j = i + 1; j < line.size(); j++) {
					if (line.at(j) != ' ') {
						nameToLoad.resize(j+1);
						nameToLoad.at(s) = line.at(j);
						s++;
					}
				}
			}
		}

		//ARCHETYPE
		getline(saveDataTxt, line);
		for (int i = 0; i < line.size(); i++) {
			if (line.at(i) == startReadMarker)
			{

				for (int j = i + 1; j < line.size(); j++) {
					if (line.at(j) != ' ') {
						archetypeToLoad = line.at(j) - 48;
					}
				}
			}
		}

		//STATS
		getline(saveDataTxt, line);
		for (int i = 0; i < line.size(); i++) {
			if (line.at(i) == startReadMarker)
			{
				int s = 0;
				for (int j = i + 1; j < line.size(); j++) {
					if (line.at(j) != ' ') {
						statsToLoad[s] = line.at(j);
						s++;
					}
				}
			}
		}

		//ITEM IDS
		getline(saveDataTxt, line);
		for (int i = 0; i < line.size(); i++) {
			if (line.at(i) == startReadMarker)
			{
				int s = 0;
				for (int j = i + 1; j < line.size(); j++) {
					if (line.at(j) != ' ') {
						itemIdsToLoad[s] = line.at(j);
						s++;
					}
				}
			}
		}

	}
	else {
		cout << "Failed to load game!" << endl;
	}
	newPlayer.name = nameToLoad;
	newPlayer.archetype = archetypeToLoad;
	for (int i = 0; i < 5; i++) {
		newPlayer.stats[i] = statsToLoad[i] - 48;
	}
	for (int i = 0; i < 5; i++) {
		newPlayer.inventory[i] = itemDatabase[(itemIdsToLoad[i] - 48)];
	}
	

	//close file
	saveDataTxt.close();

	system("PAUSE");
	system("CLS");
	return newPlayer;
}