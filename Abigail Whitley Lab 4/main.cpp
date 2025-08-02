/*Create a text turn - based battle game with Java :
Allow the player to choose from a list of weapons before the battle begins.
Randomly generate the stats of the enemy the player fights.
On the player's turn, allow them to choose by selecting a number to fight or heal. Track both health points and mana.
On the enemy's turn, it can either attack or heal using random chance.
The battle ends when either the player or the enemy's HP reaches 0*/

#include "EasyMonster.h"
#include "HardMonster.h"
#include "Monsters.h"
#include "Dagger.h"
#include "Sword.h"
#include "Wand.h"
#include "Weapons.h"
#include "Health.h"
#include "Randomizer.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));

	int userWeaponChoice, userDifficultyChoice, userAction, enemyAction, enemyHealAmount, damageAmount, enemyDamageAmount;
	Weapons* weapon = nullptr;
	Monsters* enemy  =nullptr;
	Health potion;
	Player player;

	while (true) {
		while (!weapon) {
			cout << "Which weapon would you like to choose? 1. Dagger (1-3 damage), 2. Sword (4-5 damage), 3. Wand (1-8 damage)." << endl;
			cin >> userWeaponChoice;

			if (userWeaponChoice == 1) {
				weapon = new Dagger();
				cout << "You wield a " << weapon->getName() << "!" << endl;
			}
				
			else if (userWeaponChoice == 2) {
				weapon = new Sword();
				cout << "You wield a " << weapon->getName() << "!" << endl;
			}

			else if (userWeaponChoice == 3) {
				weapon = new Wand();
				cout << "You wield a " << weapon->getName() << "!" << endl;
			}

			else {
				cout << "Invalid choice. Try again.\n";
			}
		}

		while (!enemy) {
			cout << "Which difficulty level would you like to choose? 1. Easy, 2. Hard." << endl;
			cin >> userDifficultyChoice;

			if (userDifficultyChoice == 1) {
				enemy = new EasyMonster();
			}
			else if (userDifficultyChoice == 2) {
				enemy = new HardMonster();
			}
			else {
				cout << "Invalid choice. Try again.\n";
			}
		}

		cout << "Your monster is a " << enemy->getName() << " with " << enemy->getMonsterHealth() << " health." << endl;

		cout << "Would you like to 1. attack, or 2. heal?" << endl;
		cin >> userAction;

		if (userAction == 1) {
			while (true) {
				damageAmount = weapon->getWeaponDamage();
				cout << weapon->use() << endl;
				enemy->takeDamage(damageAmount);

				if (enemy->getMonsterHealth() <= 0) {
					break;
				}

				if (Dagger* dagger = dynamic_cast<Dagger*>(weapon)) {
					if (dagger->extraTurn()) {
						cout << "You struck so fast you get another turn!" << endl;
						continue;
					}
				}
				break;
			}
		}

		else if (userAction == 2) {
			cout << potion.use() << endl;
			player.heal(potion.getHealAmount());
		}

		else {
			cout << "Please enter 1 or 2." << endl;
			cin >> userAction;
		}

		cout << "Monster health: " << enemy->getMonsterHealth() << endl;
		cout << "User health: " << player.getHealth() << "/" << player.getMaxHealth() << endl;

		if (enemy->getMonsterHealth() <= 0) {
			cout << "You defeated the " << enemy->getName() << "!" << endl;
			break;
		}

		enemyAction = rand() % 2;

		if (enemyAction == 0) {
			enemyDamageAmount = enemy->getMonsterDamage();
			player.takeDamage(enemyDamageAmount);
			cout << enemy->getName() << " attacked for " << enemyDamageAmount << " damage!" << endl;
		}

		else {
			enemyHealAmount = rand() % 6 + 5;
			enemy->heal(enemyHealAmount);
			cout << enemy->getName() << " healed for " << enemyHealAmount << " points." << endl;
		}

		if (player.isDead()) {
			cout << "You were defeated by the " << enemy->getName() << endl;
			break;
		}
	}


	delete weapon;
	delete enemy;

	return 0;
}