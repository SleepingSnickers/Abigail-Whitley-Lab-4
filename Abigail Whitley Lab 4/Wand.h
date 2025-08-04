#pragma once
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>

using namespace std;

class Wand :
    public Weapons
{
public:
    //constructor
    Wand();

    //use override
    string use() const override;
};

