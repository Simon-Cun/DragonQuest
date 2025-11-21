#pragma once
#include "Items.h"
#include <string>
using namespace std;

class Armor : public Items {
    protected:
        float defenseMod;
        float dodgeMod;
    public:
        void setDefenseMod(float);
        void setDodgeMod(float);
};