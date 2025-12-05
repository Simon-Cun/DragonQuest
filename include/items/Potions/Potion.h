#pragma once
#include "Items.h"
#include <string>
using namespace std;

class Potion : public Items {
    protected:
        float healthMod;
        float attackMod;

    public:
        Potion();
        void setHealthMod(float);
        void setAttackMod(float);
};