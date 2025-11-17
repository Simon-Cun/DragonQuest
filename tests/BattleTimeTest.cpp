#include "gtest/gtest.h"
#include "BattleTime.h"
#include "PlayerClasses.h"
#include "Enemy.h"

int rand() { return 0; }

class TestPlayer : public PlayerClasses {
public:
    TestPlayer() {
        setPlayerATK(10);
        setPlayerDEF(5);
        setPlayerDodge(0); 
        setPlayerHP(50);
    }
};

class TestEnemy : public Enemy {
public:
    TestEnemy() {
        setAttackStat(8);
        setDefenseStat(3);
        setHealthStat(40);
        setRunChance(0.0f);
    }
};

TEST(BattleTimeTest, HandleAttack) {
    BattleTime bt;
    TestPlayer player;
    TestEnemy enemy;

    bt.handleAttack(player, enemy);

    EXPECT_FLOAT_EQ(enemy.getHealthStat(), 40 - 7);
}

TEST(BattleTimeTest, HandleHeal) {
    BattleTime bt;
    TestPlayer player;
    player.setPlayerHP(30);

    bt.handleHeal(player);

    EXPECT_FLOAT_EQ(player.getPlayerHP(), 30 + 20);
}

TEST(BattleTimeTest, HandleDefend) {
    BattleTime bt;
    TestPlayer player;

    bt.handleDefend(player);

    EXPECT_TRUE(bt.isBlocking);
}

TEST(BattleTimeTest, HandleRunSuccess) {
    BattleTime bt;
    TestPlayer player;
    TestEnemy enemy;

    player.setPlayerDodge(100);  
    enemy.setRunChance(0.0f);    

    EXPECT_TRUE(bt.handleRun(player, enemy));
}

TEST(BattleTimeTest, HandleRunFail) {
    BattleTime bt;
    TestPlayer player;
    TestEnemy enemy;

    player.setPlayerDodge(0);
    enemy.setRunChance(0.0f);

    EXPECT_FALSE(bt.handleRun(player, enemy));
}

TEST(BattleTimeTest, EnemyTurn) {
    BattleTime bt;
    TestPlayer player;
    TestEnemy enemy;

    enemy.setAttackStat(8);
    player.setPlayerDEF(5);

    float oldHP = player.getPlayerHP();

    bt.enemyTurn(player, enemy);

    EXPECT_FLOAT_EQ(player.getPlayerHP(), oldHP - 3);
}