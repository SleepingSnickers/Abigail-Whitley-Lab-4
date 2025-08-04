#include "Health.h"

#include <iostream>
#include <string>

using namespace std;

//default constructor, sets the health potion to heal between 10-20
Health::Health() {
	setLowerRandomizerBound(10);
	setUpperRandomizerBound(20);
}

//constructor to set the bounds of the health potion
Health::Health(int lowerRandomizerBound, int upperRandomizerBound) {
	setLowerRandomizerBound(lowerRandomizerBound);
	setUpperRandomizerBound(upperRandomizerBound);
}

//destructor
Health::~Health() {

}

//getter
int Health::getHealAmount() const {
	return getRandomValue();
}

//allows the user to see a unique heal line, displays how much they heal for
string Health::use() const {
	int healAmount = getHealAmount();
	return "Potion healed you for " + std::to_string(healAmount) + " HP.";
}