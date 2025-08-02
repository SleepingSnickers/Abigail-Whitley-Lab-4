#include "Health.h"

#include <iostream>
#include <string>

using namespace std;

Health::Health() {
	setLowerRandomizerBound(10);
	setUpperRandomizerBound(20);
}

Health::Health(int lowerRandomizerBound, int upperRandomizerBound) {
	setLowerRandomizerBound(lowerRandomizerBound);
	setUpperRandomizerBound(upperRandomizerBound);
}

Health::~Health() {

}

int Health::getHealAmount() const {
	return getRandomValue();
}

string Health::use() const {
	int healAmount = getHealAmount();
	return "Potion healed you for " + std::to_string(healAmount) + " HP.";
}