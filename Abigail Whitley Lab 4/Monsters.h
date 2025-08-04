#pragma once

#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

class Monsters
{
protected:
	//allows the monster to be named
	string name;
	//tracks the monster's randomly generated health
	int health;
	//keeps the monster from overhealing
	int maxHealth;
	//randomly generates the health and damage of the monster by calling the randomizer class
	Randomizer healthRange;
	Randomizer damageRange;

public:
	//constructors
	Monsters();
	Monsters(string, Randomizer, Randomizer);
	//destructor
	virtual ~Monsters();

	//getters and setters
	string getName() const;
	int getMonsterDamage() const;
	int getMonsterHealth() const;

	//subtracts players damage from monster health
	void takeDamage(int);
	//adds healing to the monster health
	void heal(int);

	//pure virtual attacK() function to allow sub-classes to override
	virtual string attack() = 0;
};

