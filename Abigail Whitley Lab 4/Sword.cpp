#include "Sword.h"
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

Sword::Sword() : Weapons("Sword", 6, 8) {

}

string Sword::use() const {
	return getName() + " slashes for " + to_string(getWeaponDamage()) + " damage.";
}