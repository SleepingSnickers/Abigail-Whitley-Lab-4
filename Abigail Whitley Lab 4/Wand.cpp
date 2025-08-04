#include "Wand.h"
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>
#include <string>

using namespace std;

//constructor sets the name to Wand and damage range between 1-10
Wand::Wand() : Weapons("Wand", 1, 10) {

}

//unique use() line that tells user how much damage they dealt
string Wand::use() const {
	return getName() + " sparks for " + to_string(getWeaponDamage()) + " damage.";
}