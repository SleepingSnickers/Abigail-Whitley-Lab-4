#pragma once
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>

using namespace std;

class Dagger :
    public Weapons
{
public:
    //constructor
    Dagger();

    //use weapon
    string use() const override;

    //allows the dagger class to have a 25% chance to move again
    bool extraTurn();
};

