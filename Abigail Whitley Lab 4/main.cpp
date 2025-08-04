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
	//seed the random variables
	srand(time(0));

	//initialize all the needed variables
	int userWeaponChoice, userDifficultyChoice, userAction, enemyAction, enemyHealAmount, damageAmount, enemyDamageAmount;
	Weapons* weapon = nullptr;
	Monsters* enemy  =nullptr;
	Health potion;
	Player player;

	//while loop to allow the different aspects of the games to be looped
	while (true) {
		//loop to make sure the user chooses an appropriate weapon
		while (!weapon) {
			//user chooses a weapon and stores it into appropriate variable
			cout << "Which weapon would you like to choose? 1. Dagger (1-3 damage), 2. Sword (4-5 damage), 3. Wand (1-8 damage)." << endl;
			cin >> userWeaponChoice;

			//sets users weapon to a new Dagger
			if (userWeaponChoice == 1) {
				weapon = new Dagger();
				cout << "You wield a " << weapon->getName() << "!" << endl;
			}
			
			//sets users weapon to a new Sword
			else if (userWeaponChoice == 2) {
				weapon = new Sword();
				cout << "You wield a " << weapon->getName() << "!" << endl;
			}

			//sets users weapon to a new Wand
			else if (userWeaponChoice == 3) {
				weapon = new Wand();
				cout << "You wield a " << weapon->getName() << "!" << endl;
			}

			//restarts the loop to ensure user chooses a weapon
			else {
				cout << "Invalid choice. Try again.\n";
			}
		}

		//same concept as the weapons loop, the choice is between an easy monster and a hard monster
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

		//allows the user to see the current status
		cout << "Your monster is a " << enemy->getName() << " with " << enemy->getMonsterHealth() << " health." << endl;

		//user can choose to attack or heal
		cout << "Would you like to 1. attack, or 2. heal?" << endl;
		cin >> userAction;

		//loop to start the attack sequence
		if (userAction == 1) {
			while (true) {
				damageAmount = weapon->getWeaponDamage();
				cout << weapon->use() << endl;
				enemy->takeDamage(damageAmount);

				//if the enemy dies, the game ends
				if (enemy->getMonsterHealth() <= 0) {
					break;
				}

				//allows for the 25% chance of a second move if you have a dagger
				if (Dagger* dagger = dynamic_cast<Dagger*>(weapon)) {
					if (dagger->extraTurn()) {
						cout << "You struck so fast you get another turn!" << endl;
						continue;
					}
				}
				break;
			}
		}

		//allows the user to heal
		else if (userAction == 2) {
			cout << potion.use() << endl;
			player.heal(potion.getHealAmount());
		}

		//ensures the user chooses an appropriate action
		else {
			cout << "Please enter 1 or 2." << endl;
			cin >> userAction;
		}

		//displays the monster and players health
		cout << "Monster health: " << enemy->getMonsterHealth() << endl;
		cout << "User health: " << player.getHealth() << "/" << player.getMaxHealth() << endl;

		//shows if the monster is dead
		if (enemy->getMonsterHealth() <= 0) {
			cout << "You defeated the " << enemy->getName() << "!" << endl;
			break;
		}

		//randomly chooses if the monster attacks or heals
		enemyAction = rand() % 2;

		//monster attacks if the generated number is 0
		if (enemyAction == 0) {
			enemyDamageAmount = enemy->getMonsterDamage();
			player.takeDamage(enemyDamageAmount);
			cout << enemy->getName() << " attacked for " << enemyDamageAmount << " damage!" << endl;
		}

		//monster heals in other cases
		else {
			enemyHealAmount = rand() % 6 + 5;
			enemy->heal(enemyHealAmount);
			cout << enemy->getName() << " healed for " << enemyHealAmount << " points." << endl;
		}

		//checks if the player is dead
		if (player.isDead()) {
			cout << "You were defeated by the " << enemy->getName() << endl;
			break;
		}
	}

	//deletes the dynamically allocated variables
	delete weapon;
	delete enemy;

	return 0;
}