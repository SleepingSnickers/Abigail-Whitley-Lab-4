#pragma once

#include "Randomizer.h"

#include <iostream>

using namespace std;

class Health :
    public Randomizer
{
public:
    //constructors
    Health();
    Health(int, int);
    //destructor
    ~Health();

    //getter for healAmount
    int getHealAmount() const;

    //use() function to allow player to use a health potion
    string use() const;
};

