#include "EasyMonster.h"

#include <iostream>
#include <string>

using namespace std;

//sets the EasyMonster class to be one of three randomly chosen names, health between 10-16, and damage to be between 5-10
EasyMonster::EasyMonster() : Monsters("", Randomizer (10, 16), Randomizer (5, 10)) {
	vector<string> names = { "Werewolf", "Zombie", "Goblin" };
	name = names[rand() % names.size()];
}

//shows how much damage the monster did
string EasyMonster::attack() {
	return name + " did " + to_string(getMonsterDamage()) + " damage";
}