#include "Sword.h"
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

//constructor, sets name to Sword and damage range between 6-8
Sword::Sword() : Weapons("Sword", 6, 8) {

}

//unique use() line, shows how much damage the user dealt
string Sword::use() const {
	return getName() + " slashes for " + to_string(getWeaponDamage()) + " damage.";
}