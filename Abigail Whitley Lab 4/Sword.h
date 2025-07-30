#pragma once
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>

using namespace std;

class Sword :
    public Weapons
{
public:
    Sword();

    string use() const override;
};

