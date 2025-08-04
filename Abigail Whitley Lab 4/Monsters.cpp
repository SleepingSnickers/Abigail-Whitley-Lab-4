#include <iostream>
#include <string>

#include "Monsters.h"

using namespace std;

//default constructor setting everything to 0/blank
Monsters::Monsters(): healthRange(), damageRange() {
	name = " ";
	health = 0;
	maxHealth = 0;
}

//sets each of the arguments
Monsters::Monsters(string name, Randomizer healthRange, Randomizer damageRange) {
	this->name = name;
	this->healthRange = healthRange;
	this->damageRange = damageRange;

	//health gets set to a randomly generated value, maxHealth gets set to health
	health = healthRange.getRandomValue();
	maxHealth = health;
}

//destructor
Monsters::~Monsters() {

}

//getters
string Monsters::getName() const {
	return name;
}

int Monsters::getMonsterDamage() const {
	return damageRange.getRandomValue();
}

int Monsters::getMonsterHealth() const {
	return health;
}

//subtracts the damage the monster takes from the health
void Monsters::takeDamage(int damage) {
	health -= damage;
	//if health dips below 0, health gets set to 0. This makes it easier to prevent bugs
	if (health < 0) {
		health = 0;
	}
}

//allows the monster to heal without overhealing
void Monsters::heal(int amount) {
	health += amount;
	if (health > maxHealth) {
		health = maxHealth;
	}
}