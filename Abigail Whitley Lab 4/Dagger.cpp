#include "Dagger.h"
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

Dagger::Dagger() : Weapons("Dagger",  1, 3) {

}

string Dagger::use() const {
	return getName() + " swipes for " + to_string(getWeaponDamage()) + " damage.";
}

bool Dagger::extraTurn() {
	return rand() % 100 < 25;
}