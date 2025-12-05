#pragma once
#include "PlayerClasses.h"
#include "Enemy.h"

#ifdef GTEST
#include "gtest/gtest_prod.h"
#endif

class BattleTime {
public:
    BattleTime();

    void startBattle(PlayerClasses& player, Enemy& enemy);

private:
#ifdef GTEST
    FRIEND_TEST(BattleTimeTest, HandleAttack);
    FRIEND_TEST(BattleTimeTest, HandleHeal);
    FRIEND_TEST(BattleTimeTest, HandleDefend);
    FRIEND_TEST(BattleTimeTest, HandleRunSuccess);
    FRIEND_TEST(BattleTimeTest, HandleRunFail);
    FRIEND_TEST(BattleTimeTest, EnemyTurn);
#endif
    
    bool isBlocking;

    bool escaped;

    void playerTurn(PlayerClasses& player, Enemy& enemy);
    void handleAttack(PlayerClasses& player, Enemy& enemy);
    void handleHeal(PlayerClasses& player);
    void handleDefend(PlayerClasses& player);
    bool handleRun(PlayerClasses& player, Enemy& enemy);

    void enemyTurn(PlayerClasses& player, Enemy& enemy);
    void displayBattleMenu(PlayerClasses& player, Enemy& enemy);
};
