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

	int numStory;
	int numOptions;

	Scene(string story[5], string options[5], int numStory, int numOptions);

	int play();	
};

