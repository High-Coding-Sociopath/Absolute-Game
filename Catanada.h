#pragma once
#ifndef Header.h
#include "Items.h"
#include "Spells.h"
#include "PlayerData.h"
#define LINE cout << "-------------------------\n" << endl;
#endif

int gettingstarted();//Linked in right through inn_chat(), just for the quest
int highwayman();//Maybe add an if thing for the currentquest and make it much more viable to use under other circumstances

int gettingstarted() {
	map catanada_map{ 2, 19, "Catanada Map", "Some roads", "a couple of small towns marked around", "a hill just north of the city", "a river that slithers down the hill and goes parallel to the road to the city entrance" };
	misc compass{ 5, 20, "Compass", "Shows which way is north." };
	cout << "People have gone back to their homes now, and the sky is outright black, save for the little blinking stars staring over. 'Stay here just a moment.' the woman says, and goes into the";
	cout << " travelers' shop, coming out about a minute later. She walks over and hands you a compass and a hand-drawn map, showing some handy places. 'Keep these handy, the compass is on me.'" << endl;
	cout << "She stands still for a second, and reaches her hand out. 'I'm Kalin, by the way.' You take her hand. '" << name << ", nice to know ya.' She smiles and starts walking east, according to your new compass. 'Hope you had some sleep earlier, " << name << ", because we've got some roads to walk.'" << endl;
	inventory.push_back(catanada_map);
	inventory.push_back(compass);

	return highwayman();
}

int highwayman() {
	return 0;
}