#pragma once
#include "Monsters.h"
#include "Randomizer.h"

#include <iostream>
#include <vector>

using namespace std;


class HardMonster :
    public Monsters
{
public:
    //constructor
    HardMonster();

    //attack() override
    string attack() override;
};

