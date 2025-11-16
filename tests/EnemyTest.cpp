#include "gtest/gtest.h"
#include "Enemy.h"

TEST(EnemyTest, SetHealthStatWorks) {
    Enemy enemy;
    const float newHealth = 75.0;
    enemy.setHealthStat(newHealth);
    EXPECT_EQ(enemy.getHealthStat(), newHealth);
}

TEST(EnemyTest, SetAttackStatWorks) {
    Enemy enemy;
    const float newAttack = 75.0;
    enemy.setAttackStat(newAttack);
    EXPECT_EQ(enemy.getAttackStat(), newAttack);
}

TEST(EnemyTest, SetDefenseStatWorks) {
    Enemy enemy;
    const float newDefense = 75.0;
    enemy.setDefenseStat(newDefense);
    EXPECT_EQ(enemy.getDefenseStat(), newDefense);
}

TEST(EnemyTest, SetRunChanceWorks) {
    Enemy enemy;
    const float runChance = 0.05;
    enemy.setRunChance(runChance);
    EXPECT_EQ(enemy.getRunChance(), runChance);
}

TEST(EnemyTest, SetExpDropWorks) {
    Enemy enemy;
    const float expDrop = 100.0;
    enemy.setExpDrop(expDrop);
    EXPECT_EQ(enemy.getExpDrop(), expDrop);
}