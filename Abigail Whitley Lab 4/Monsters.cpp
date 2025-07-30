#include <iostream>
#include <string>

#include "Monsters.h"

using namespace std;

Monsters::Monsters(): healthRange(), damageRange() {
	name = " ";
	health = 0;
}

Monsters::Monsters(string name, Randomizer healthRange, Randomizer damageRange) {
	this->name = name;
	this->healthRange = healthRange;
	this->damageRange = damageRange;

	health = healthRange.getRandomValue();
}

Monsters::~Monsters() {

}

string Monsters::getName() const {
	return name;
}

int Monsters::getMonsterDamage() const {
	return damageRange.getRandomValue();
}

int Monsters::getMonsterHealth() const {
	return health;
}