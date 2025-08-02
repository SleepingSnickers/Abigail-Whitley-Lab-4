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
	maxHealth = health;
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

void Monsters::takeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

void Monsters::heal(int amount) {
	health += amount;
	if (health > maxHealth) {
		health = maxHealth;
	}
}