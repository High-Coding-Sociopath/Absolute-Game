#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int action;

struct spell {
public:
	string name;
	string description;
	int identifier{};
};

struct fireball :public spell {
public:

	void blast() {
		cout << "A small bead appears at your fingertip, then becomes a ball the size of a carriage wheel to explode at your enemies' feet, burning them up and setting the objects around on fire!" << endl;
	}

};

struct frost : public spell {
public:void freeze() {
	cout << "You freeze your enemy stuck in ice, rendering incapable of moving or attacking." << endl;
}
};

struct light :public spell {
public:void light_up() {
	cout << "A ball of light appears and follows you as you make your way through the rooms." << endl;
}
	  void light_out() {
		  cout << "The light disappears." << endl;
	  }
};

struct shieldspell :public spell {
	void up() {
		cout << "A spectral shield appears momentarily before you get hit, blocking the attack." << endl;
	}
};

