#include "HardMonster.h"

#include <iostream>
#include <string>

using namespace std;

//sets the HardMonster class to be one of three randomly chosen names, health between 15-21, and damage to be between 10-20
HardMonster::HardMonster() : Monsters("", Randomizer (15, 21), Randomizer (10, 20)) {
	vector<string> names = { "Hydra", "Dragon", "Kraken" };
	name = names[rand() % names.size()];
}

//shows how much damage the monster did
string HardMonster::attack() {
	return name + " did " + to_string(getMonsterDamage()) + " damage";
}