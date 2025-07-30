#include "HardMonster.h"

#include <iostream>
#include <string>

using namespace std;

HardMonster::HardMonster() : Monsters("", Randomizer (15, 21), Randomizer (10, 20)) {
	vector<string> names = { "Hydra", "Dragon", "Kraken" };
	name = names[rand() % names.size()];
}

string HardMonster::attack() {
	return name + " did " + to_string(getMonsterDamage()) + " damage";
}