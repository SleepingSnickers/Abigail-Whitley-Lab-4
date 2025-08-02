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
	Weapons();
	Weapons(string, int, int);
	virtual ~Weapons();

	string getName() const;
	int getWeaponDamage() const;
	
	virtual string use() const = 0;
};

