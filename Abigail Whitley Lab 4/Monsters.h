#pragma once

#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

class Monsters
{
protected:
	string name;
	int health;
	Randomizer healthRange;
	Randomizer damageRange;

public:
	Monsters();
	Monsters(string, Randomizer, Randomizer);
	virtual ~Monsters();

	string getName() const;
	int getMonsterDamage() const;

	int getMonsterHealth() const;

	virtual string attack() = 0;
};

