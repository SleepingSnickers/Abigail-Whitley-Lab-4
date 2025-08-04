#include <iostream>
#include <string>

#include "Weapons.h"
#include "Randomizer.h"

using namespace std;

//default constructor
Weapons::Weapons() {
	name = " ";
	lowerRandomizerBound = 0;
	upperRandomizerBound = 0;
}

//sets incoming variables to class variables
Weapons::Weapons(string name, int lowerRandomizerBound, int upperRandomizerBound) {
	this->name = name;
	this->lowerRandomizerBound = lowerRandomizerBound;
	this->upperRandomizerBound = upperRandomizerBound;
}

//destructor
Weapons::~Weapons() {

}

//getters
string Weapons::getName() const {
	return name;
}

int Weapons::getWeaponDamage() const {
	return getRandomValue();
}