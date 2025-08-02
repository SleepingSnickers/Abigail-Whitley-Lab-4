#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

Player::Player(int maxHealth) {
	this->health = maxHealth;
	this->maxHealth = maxHealth;
}

Player::~Player() {

}

int Player::getHealth() const {
	return health;
}

int Player::getMaxHealth() const {
	return maxHealth;
}

void Player::takeDamage(int amount) {
	health -= amount;
	if (health < 0) {
		health = 0;
	}
}

void Player::heal(int amount) {
	health += amount;
	if (health > maxHealth) {
		health = maxHealth;
	}
}

bool Player::isDead() const {
	return health <= 0;
}