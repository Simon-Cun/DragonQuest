#include "PlayerClasses.h"
#include "Items.h"
#include "Weapon.h"
#include <string>
using namespace std;

Weapon::Weapon() : attackMod(10), dropMod(0), dodgeMod(0) {

}

void Weapon::setAttackMod(float atk) {
    attackMod = atk;
}

void Weapon::setDropMod(float drop) {
    dropMod = drop;
}

void Weapon::setDodgeMod(float dodge) {
    dodgeMod = dodge;
}