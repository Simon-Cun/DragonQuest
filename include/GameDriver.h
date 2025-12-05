#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

#include <string>

#include "PlayerClasses.h"
#include "BattleTime.h"
#include "Enemy.h"

#include "Mage.h"
#include "Warrior.h"
#include "Rogue.h"

#include "Items.h"
#include "Frostforged.h"
#include "Thunderfury.h"
#include "Weapon.h"
#include "Potion.h"
#include "Armor.h"
#include "LesserHealthPotion.h"
#include "GreaterHealthPotion.h"
#include "Obsidiansentinel.h"
#include "Dragonsbane.h"

#include "Slime.h"
#include "Goblin.h"
#include "Ogre.h"
#include "Robot.h"
#include "Dragon.h"

class GameDriver {
public:
    GameDriver();
    void Menu();

private:
    PlayerClasses player;
    std::string playerName;

    Dragonsbane dragonsbane;
    Frostforged frostforged;
    Thunderfury thunderfury;
    Obsidiansentinel obsidiansentinel;
    LesserHealthPotion lesserhealthpotion;
    GreaterHealthPotion greaterhealthpotion;

    bool foughtSlime;
    bool foughtGoblin;
    bool foughtOgre;
    bool foughtRobot;

    void showTitleScreen();
    void showIntroDialogue();
    void choosePlayerName();
    void choosePlayerClass();
    void startFirstBattle();
    void explorationLoop();
    void fightEnemy(Enemy& e);

    std::string getLine();
    int randPercent();
};

#endif
