#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

//constructor
Player::Player(int maxHealth) {
	this->health = maxHealth;
	this->maxHealth = maxHealth;
}

//destructor
Player::~Player() {

}

//getters
int Player::getHealth() const {
	return health;
}

int Player::getMaxHealth() const {
	return maxHealth;
}

//allows player to take damage
void Player::takeDamage(int amount) {
	health -= amount;
	if (health < 0) {
		health = 0;
	}
}

//allows player to heal
void Player::heal(int amount) {
	health += amount;
	if (health > maxHealth) {
		health = maxHealth;
	}
}

//returns if the player is dead (health is 0 or below)
bool Player::isDead() const {
	return health <= 0;
}