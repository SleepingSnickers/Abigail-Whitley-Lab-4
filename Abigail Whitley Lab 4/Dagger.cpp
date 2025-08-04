#include "Dagger.h"
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

//constructor, sets name to Dagger, and the range of damage is between 3-5
Dagger::Dagger() : Weapons("Dagger",  3, 5) {

}

//override for the use() constructor, shows a unique message that tells how much damage the user dealt
string Dagger::use() const {
	return getName() + " swipes for " + to_string(getWeaponDamage()) + " damage.";
}

//allows for a 25% chance that the dagger can attack again
bool Dagger::extraTurn() {
	return rand() % 100 < 25;
}