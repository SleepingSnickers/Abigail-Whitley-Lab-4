#pragma once
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>

using namespace std;

class Sword :
    public Weapons
{
public:
    //constructor
    Sword();

    //use() override
    string use() const override;
};

