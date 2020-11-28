/*
	File:		Scene.h
	Author:		Brandon White

	-------------------------
	Quick Guide with Examples
	-------------------------
	1. Under "//QUEST SETUP" in main, comment in the name for your quest.
		
			// Basement Rats

	2. On the next line, create the first scene. 

			Scene* BasementRats_1 = new Scene();

	3. On the next 5 lines, fill in the blanks. Note you can only have 5 special options.

			BasementRats_1->storyLines = { "There's rats in your basement!", "They are super huge!", "What will you do?", " ", " " };
			BasementRats_1->numStoryLines = 3;
			BasementRats_1->baseOptions = { "Fight!", "Run!", "Hide!", " ", " " };
			BasementRats_1->numBaseOptions = 3;
			BasementRats_1->specialOptions = { "[Class] Raise undead rats.", " ",  "[Strength] Punch the rat!", " ", "[Inventory] Use your rat gun!" };

	4. Repeat with the rest of the scenes with your quest.

			Scene* BasementRats_2A = new Scene();

	4.5 So under "//QUEST SETUP" you should have something like this:

		// Basement Rats
			Scene* BasementRats_1 = new Scene();
				BasementRats_1->storyLines = { "There's rats in your basement!", "They are super huge!", "What will you do?", " ", " " };
				BasementRats_1->numStoryLines = 3;
				BasementRats_1->baseOptions = { "Fight!", "Run!", "Hide!", " ", " " };
				BasementRats_1->numBaseOptions = 3;
				BasementRats_1->specialOptions = { "[Class] Raise undead rats.", "[Inventory] Use your rat gun!", "[Strength] Punch the rat!", "[History] Call that guy who owes you a favor!", " " };
			Scene* BasementRats_2A = new Scene();
				// etc...

	5. Next, go down to "//GAMEPLAY LOOP" and find "while (inQuest)". Under that should be a "switch (activeQuest)". Make a new case number for your quest.

			while (inQuest) {
				switch (activeQuest) {
					// Basement Rats
					case 1:
						// The whole quest takes place between case # and break!
						break;
				}
			}

	6. Set up character history for the question.
			
			while (inQuest) {
				switch (activeQuest) {
					// Basement Rats
					case 1:
						int characterHistory[5];
						characterHistory[0] = player->

						// The whole quest takes place between case # and break!
						break;
				}
			}


	
	specialReq[0] is a class check (class ID)
	specaiaReq[1] is a class check (class ID)
	specialReq[2] is a skill check (threshold to pass)
	specialReq[3] is a skill check (threshold to pass)
	specialReq[4] is an item/bg check (true/false)

	characterHistory[0] is the player's class
	characterHistory[1] is the player's class again
	characterHistory[2] is the value of a skill to check
	characterHistory[3] is the value of another skill to check
	characterHistory[4] is the value of the item/background (do we have it) that we are checking
	

*/

#pragma once
#include "TextAdventure.h"

class Scene
{
public:
	string storyLines[5];
	string baseOptions[5];
	string specialOptions[5];

	int numStoryLines;
	int numBaseOptions;

	Scene();

	int play(int specialReqs[5], int characterHistory[5]);	
};

