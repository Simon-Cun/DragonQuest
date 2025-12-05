#pragma once
#include "Items.h"
#include <string>
using namespace std;

class Weapon : public Items {
    protected:
        float attackMod;
        float dodgeMod;
        float dropMod;
    public:
        Weapon();
        void setAttackMod(float);
        void setDropMod(float);
        void setDodgeMod(float);
};