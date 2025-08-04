#include "Randomizer.h"

//default constructor
Randomizer::Randomizer() {
	lowerRandomizerBound = 0;
	upperRandomizerBound = 0;
}

//constructor
Randomizer::Randomizer(int lowerRandomizerBound, int upperRandomizerBound) {
	this->lowerRandomizerBound = lowerRandomizerBound;
	this->upperRandomizerBound = upperRandomizerBound;
}

//getters and setters
int Randomizer::getLowerRandomizerBound() const {
	return lowerRandomizerBound;
}

void Randomizer::setLowerRandomizerBound(int lowerRandomizerBound) {
	this->lowerRandomizerBound = lowerRandomizerBound;
}

int Randomizer::getUpperRandomizerBound() const {
	return upperRandomizerBound;
}

void Randomizer::setUpperRandomizerBound(int upperRandomizerBound) {
	this->upperRandomizerBound = upperRandomizerBound;
}

int Randomizer::getRandomValue() const {
	return lowerRandomizerBound + rand() % (upperRandomizerBound - lowerRandomizerBound + 1);
}