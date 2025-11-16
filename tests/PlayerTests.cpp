#include "gtest/gtest.h"
#include "PlayerClasses.h"
#include "Mage.h"
#include "Warrior.h"
#include "Rogue.h"

TEST(PlayerTests, PlayerClassesConstructorWorks) {
    EXPECT_NO_THROW({PlayerClasses aPlayer;});
}

TEST(PlayerTests, MageConstructorWorks) {
    EXPECT_NO_THROW({PlayerClasses aMage = Mage();});
}

TEST(PlayerTests, WarriorConstructorWorks) {
    EXPECT_NO_THROW({PlayerClasses aWarrior = Warrior();});
}

TEST(PlayerTests, RogueConstructorWorks) {
    EXPECT_NO_THROW({PlayerClasses aRogue = Rogue();});
}

TEST(PlayerTests, SetPlayerName) {
    PlayerClasses p;
    EXPECT_NO_THROW({p.setPlayerName("Meep");});
}

TEST(PlayerTests, GetPlayerName) {
    PlayerClasses p;
    p.setPlayerName("Meep");
    EXPECT_EQ(p.getPlayerName(), "Meep");
}

TEST(PlayerTests, TypeIsInvalid) {
    PlayerClasses p;
    EXPECT_THROW({p.setPlayerType("Warrior");}, std::runtime_error);
}

TEST(PlayerTests, SetPlayerType) {
    PlayerClasses p;
    EXPECT_NO_THROW({p.setPlayerType("W");});
}

TEST(PlayerTests, GetPlayerTypeWarrior) {
    PlayerClasses p;
    p.setPlayerType("W");
    EXPECT_EQ(p.getPlayerType(), "WARRIOR");
}

TEST(PlayerTests, GetPlayerTypeMage) {
    PlayerClasses p;
    p.setPlayerType("M");
    EXPECT_EQ(p.getPlayerType(), "MAGE");
}

TEST(PlayerTests, GetPlayerTypeRogue) {
    PlayerClasses p;
    p.setPlayerType("R");
    EXPECT_EQ(p.getPlayerType(), "ROGUE");
}

TEST(PlayerTests, AddEXP) {
    PlayerClasses p;
    EXPECT_NO_THROW({p.addEXP(10.0);});
}

TEST(PlayerTests, LevelUpWorks) {
    PlayerClasses p;
    p.addEXP(10.0);
    EXPECT_NO_THROW({p.levelUp();});
}

TEST(PlayerTests, GetLVL1) {
    PlayerClasses p;
    p.addEXP(10.0);
    p.levelUp();
    EXPECT_EQ(p.getPlayerLevel(), 1);
}

TEST(PlayerTests, GetLVL2) {
    PlayerClasses p;
    p.addEXP(50.0);
    p.levelUp();
    EXPECT_EQ(p.getPlayerLevel(), 2);
}

TEST(PlayerTests, GetLVL3) {
    PlayerClasses p;
    p.addEXP(110.0);
    p.levelUp();
    EXPECT_EQ(p.getPlayerLevel(), 3);
}

TEST(PlayerTests, GetLVL4) {
    PlayerClasses p;
    p.addEXP(450.0);
    p.levelUp();
    EXPECT_EQ(p.getPlayerLevel(), 4);
}

TEST(PlayerTests, GetLVL5) {
    PlayerClasses p;
    p.addEXP(5000.0);
    p.levelUp();
    EXPECT_EQ(p.getPlayerLevel(), 5);
}

TEST(PlayerTests, SetAndGetATK) {
    PlayerClasses p;
    p.setPlayerATK(5.0);
    EXPECT_EQ(p.getPlayerATK(), 5.0);
}

TEST(PlayerTests, SetAndGetDEF) {
    PlayerClasses p;
    p.setPlayerDEF(5.0);
    EXPECT_EQ(p.getPlayerDEF(), 5.0);
}

TEST(PlayerTests, SetAndGetDodge) {
    PlayerClasses p;
    p.setPlayerDodge(5.0);
    EXPECT_EQ(p.getPlayerDodge(), 5.0);
}

TEST(PlayerTests, SetAndGetHP) {
    PlayerClasses p;
    p.setPlayerHP(5.0);
    EXPECT_EQ(p.getPlayerHP(), 5.0);
}
