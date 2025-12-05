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

#ifdef GTEST
#include <gtest/gtest_prod.h>
#endif

class GameDriver {
public:
    GameDriver();
    void Menu();

#ifdef GTEST
public:
    PlayerClasses& getPlayerForTesting() { return player; }
    std::string& getNameForTesting() { return playerName; }
#endif

private:

#ifdef GTEST
    FRIEND_TEST(GameDriverTests, RandPercentWithinRange);
    FRIEND_TEST(GameDriverTests, ChooseNameWorks);
    FRIEND_TEST(GameDriverTests, ChooseMageClassWorks);
    FRIEND_TEST(GameDriverTests, ChooseWarriorClassWorks);
    FRIEND_TEST(GameDriverTests, ChooseRogueClassWorks);
    FRIEND_TEST(GameDriverTests, TitleScreenPrintsCorrectly);
    FRIEND_TEST(GameDriverTests, IntroDialoguePrintsCorrectly);
    FRIEND_TEST(GameDriverTests, ExplorationNoEvent);
    FRIEND_TEST(GameDriverTests, ExplorationEnemyOrder);
    FRIEND_TEST(GameDriverTests, ExplorationLootDrop);
    FRIEND_TEST(GameDriverTests, DragonAppearsAfterAllKills);
    FRIEND_TEST(GameDriverTests, PlayerDiesEndsGame);
    FRIEND_TEST(GameDriverTests, QuitMenuExitsGame);
#endif
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
