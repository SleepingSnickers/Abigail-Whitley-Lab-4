#pragma once

#include "Randomizer.h"

#include <iostream>

using namespace std;

class Health :
    public Randomizer
{
public:
    Health();
    Health(int, int);
    ~Health();

    int getHealAmount() const;
    string use() const;
};

