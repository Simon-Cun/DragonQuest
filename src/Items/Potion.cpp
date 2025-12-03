#include "PlayerClasses.h"
#include "Items.h"
#include "Potion.h"
#include <string>
using namespace std;

Potion::Potion() : attackMod(0), healthMod(20) {

}

void Potion::setAttackMod(float atk) {
    attackMod = atk;
}

void Potion::setHealthMod(float hp) {
    healthMod = hp;
}