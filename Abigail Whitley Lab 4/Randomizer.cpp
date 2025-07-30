#include "Randomizer.h"

Randomizer::Randomizer() {
	lowerRandomizerBound = 0;
	upperRandomizerBound = 0;
}

Randomizer::Randomizer(int lowerRandomizerBound, int upperRandomizerBound) {
	this->lowerRandomizerBound = lowerRandomizerBound;
	this->upperRandomizerBound = upperRandomizerBound;
}

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