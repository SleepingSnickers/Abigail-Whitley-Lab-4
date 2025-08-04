#pragma once

#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

class Weapons : public Randomizer
{
protected:
	string name;

public:
	//constructors
	Weapons();
	Weapons(string, int, int);
	//destructor
	virtual ~Weapons();

	//getters
	string getName() const;
	int getWeaponDamage() const;
	
	//pure virtual use() function to allow each weapon to have a unique usage override
	virtual string use() const = 0;
};

