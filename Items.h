#pragma once
#define LINE cout << "-------------------------\n" << endl;
#include <iostream>
#include <vector>
#include <algorithm>
#include "Spells.h"
using namespace std;

struct items {
	int itemgold, identifier;
	string itemname, description;

	const std::string& getInv() const {
		return itemname;
	}

	const std::string& getTrades() const {
		return itemname;
	}

	const int& getTradeCost() const {
		return itemgold;
	}
	const int& getID() const {
		return identifier;
	}

	
};

struct weapons :items {
	int damage;
public: bool attack() {
		cout << "You deal " << damage << "damage." << endl;
		return true;
	}
	
};

struct armor : items {
	int bonushp;
	//Something to add the following if the item is in player inventory
	//hp=hp+bonushp;
};

struct shield :armor {
	int shieldhp;
public:bool block() {
		cout << "You raise your shield and take no damage, though your shield is damaged by the hit." << endl;
		shieldhp = shieldhp - 1;

		if (shieldhp == 0) {
			cout << "Your shield breaks from taking too many hits - you'll need to find another one." << endl;
		
		}
		return true;
	}

};

struct misc :items {
	
};

struct map :misc {
	string locations[5];

public:bool getlocations() {
		cout << "You look at the map and see ";
		for (int index{}; index <= 4; index++) {
			cout << locations[index] << ", ";
		}
		cout << "marked on the map." << endl;
		return true;
	}
};

struct spellbook :misc {
	std::vector <spell> spellsinside;
	
	void getspells() {

		cout << "Pick the spell you want to use:" << endl;
		LINE
			for (int index{}; index <= spellsinside.size(); index++) {
			cout << index << ") " << spellsinside[index].name << endl;
		}

		cin >> action;
	}
};


