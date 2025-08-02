#include <iostream>
#include <string>

#include "Weapons.h"
#include "Randomizer.h"

using namespace std;

Weapons::Weapons() {
	name = " ";
	lowerRandomizerBound = 0;
	upperRandomizerBound = 0;
}

Weapons::Weapons(string name, int lowerRandomizerBound, int upperRandomizerBound) {
	this->name = name;
	this->lowerRandomizerBound = lowerRandomizerBound;
	this->upperRandomizerBound = upperRandomizerBound;
}

Weapons::~Weapons() {

}

string Weapons::getName() const {
	return name;
}

int Weapons::getWeaponDamage() const {
	return getRandomValue();
}