#pragma once

#include <string>
using namespace std;

class Player
{
private:
	//just like in the Monster class, the user can track how much health they have while preventing overhealing
	int health;
	int maxHealth;
	
public:
	//constructor
	Player(int maxHealth = 100);
	//destructor
	virtual ~Player();

	//getters
	int getHealth() const;
	int getMaxHealth() const;

	//same as Monster class, the player can both take damage and heal
	void takeDamage(int);
	void heal(int);
	//checks to see if the players health is above 0, if not the game ends
	bool isDead() const;
};

