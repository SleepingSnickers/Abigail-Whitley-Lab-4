#pragma once
#include "Weapons.h"
#include "Randomizer.h"

#include <iostream>

using namespace std;

class Wand :
    public Weapons
{
public:
    Wand();

    string use() const override;
};

