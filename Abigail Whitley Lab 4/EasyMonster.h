#pragma once
#include "Monsters.h"

#include <iostream>
#include <vector>

using namespace std;

class EasyMonster :
    public Monsters
{
public:
    //constructor
    EasyMonster();

    //attack() override
    string attack() override;
};

