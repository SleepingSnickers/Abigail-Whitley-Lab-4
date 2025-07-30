#include "Wand.h"
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

Wand::Wand() : Weapons("Wand", 1, 8) {

}

string Wand::use() const {
	return getName() + " sparks for " + to_string(getWeaponDamage()) + " damage.";
}