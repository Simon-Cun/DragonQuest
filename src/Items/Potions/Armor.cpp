#include "PlayerClasses.h"
#include "Items.h"
#include "Armor.h"
#include <string>
using namespace std;

Armor::Armor() : defenseMod(10), dodgeMod(0) {

}

void Armor::setDefenseMod(float def) {
    defenseMod = def;
}

void Armor::setDodgeMod(float dodge) {
    dodgeMod = dodge;
}