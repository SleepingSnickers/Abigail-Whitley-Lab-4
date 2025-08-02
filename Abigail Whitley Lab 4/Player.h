#pragma once

#include <string>
using namespace std;

class Player
{
private:
	int health;
	int maxHealth;
	
public:
	Player(int maxHealth = 100);
	virtual ~Player();

	int getHealth() const;
	int getMaxHealth() const;

	void takeDamage(int);
	void heal(int);
	bool isDead() const;
};

