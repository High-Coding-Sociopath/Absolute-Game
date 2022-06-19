#pragma once
#include <iostream>
#include <vector>
#include "Items.h"
using namespace std;

//A couple of things for the erase_item bool:
string deleted;
int which_one;//<-- Don't delete this because it's useful for choosing an item to be deleted.





//A function to remove an item from inventory
bool erase_item(std::vector<items>& inventory, int identifier) {
	for (auto it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it).identifier == identifier) {
			inventory.erase(it);
			return true;
		}
	}
	return false;
}



//Inventory vector to contain all items the player has
std::vector <items> inventory{};


//Variables for the player
string name;
int hp = 50, gold = 30;

int die() {
	while (action != 0) {
		if (hp <= 0) {
			cout << "You died - Game Over!" << endl;
			return 10;
		}
		else die();
	}
}