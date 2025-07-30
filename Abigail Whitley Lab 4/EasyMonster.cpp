#include "EasyMonster.h"

#include <iostream>
#include <string>

using namespace std;

EasyMonster::EasyMonster() : Monsters("", Randomizer (10, 16), Randomizer (5, 10)) {
	vector<string> names = { "Werewolf", "Zombie", "Goblin" };
	name = names[rand() % names.size()];
}

string EasyMonster::attack() {
	return name + " did " + to_string(getMonsterDamage()) + " damage";
}