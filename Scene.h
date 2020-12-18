/*
	File:		Scene.h
	Author:		Brandon White
*/

#pragma once
#include "TextAdventure.h"

class Scene
{
public:
	string story[5];
	string options[5];
	string secretOptions[5];

	int numStory;
	int numOptions;
	int numSecret;

	int matchOrBeat[5]; // A value of 0 is beat, 1 is match.
	int secretReqs[5];

	Scene();
	Scene(string fileLocation, int sceneNum);
	Scene(string story[5], string options[5], int numStory, int numOptions);

	int play(int relevantHist[5]);
};

