#include "gtest/gtest.h"

#include "Items.h"

#include "Armor.h"
#include "Dragonsbane.h"
#include "Obsidiansentinel.h"

#include "Potion.h"
#include "LesserHealthPotion.h"
#include "GreaterHealthPotion.h"

#include "Weapon.h"
#include "Frostforged.h"
#include "Thunderfury.h"

TEST(ItemsTest, DefaultConstructor) {
    Items item;
    EXPECT_EQ(item.getName(), "");
    EXPECT_EQ(item.getDescription(), "");
}

TEST(ItemsTest, SetName) {
    Items item;
    item.setName("Magic Feather");
    EXPECT_EQ(item.getName(), "Magic Feather");
}

TEST(ItemsTest, SetDescription) {
    Items item;
    item.setDescription("A rare glowing feather");
    EXPECT_EQ(item.getDescription(), "A rare glowing feather");
}

TEST(ArmorTest, DefaultArmorConstructor) {
    Armor a;
    EXPECT_EQ(a.getName(), "");
    EXPECT_EQ(a.getDescription(), "");
}

TEST(ArmorTest, DragonsbaneConstructor) {
    Dragonsbane db;
    EXPECT_EQ(db.getName(), "");
}

TEST(ArmorTest, ObsidiansentinelConstructor) {
    Obsidiansentinel obs;
    EXPECT_EQ(obs.getName(), "");
}

TEST(PotionTest, DefaultPotionConstructor) {
    Potion p;
    EXPECT_EQ(p.getName(), "");
    EXPECT_EQ(p.getDescription(), "");
}

TEST(PotionTest, LesserHealthPotionConstructor) {
    LesserHealthPotion p;
    EXPECT_EQ(p.getName(), "");
}

TEST(PotionTest, GreaterHealthPotionConstructor) {
    GreaterHealthPotion p;
    EXPECT_EQ(p.getName(), "");
}

TEST(WeaponTest, DefaultWeaponConstructor) {
    Weapon w;
    EXPECT_EQ(w.getName(), "");
    EXPECT_EQ(w.getDescription(), "");
}

TEST(WeaponTest, SetWeaponModsDoesNotCrash) {
    Weapon w;
    w.setAttackMod(12.5f);
    w.setDodgeMod(3.5f);
    w.setDropMod(0.25f);

    SUCCEED();
}

TEST(WeaponTest, FrostforgedConstructor) {
    Frostforged f;
    EXPECT_EQ(f.getName(), "");
}

TEST(WeaponTest, ThunderfuryConstructor) {
    Thunderfury t;
    EXPECT_EQ(t.getName(), "");
}
