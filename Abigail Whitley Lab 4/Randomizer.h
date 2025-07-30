#pragma once
#include <iostream>

using namespace std;

class Randomizer
{
protected:
	//the upper and lower bounds that are possible for the damage
	int lowerRandomizerBound;
	int upperRandomizerBound;
	
public:
	//constructors
	Randomizer();
	Randomizer(int, int);
	
	//getters and setters
	int getLowerRandomizerBound() const;
	void setLowerRandomizerBound(int);
	int getUpperRandomizerBound() const;
	void setUpperRandomizerBound(int);

	//generate the random damage
	int getRandomValue() const;
};

