#include "PlayerClasses.h"
#include "Items.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

PlayerClasses::PlayerClasses() 
    : playerName(""), playerType(""), playerLVL(1), playerEXPTracker(0.0f),
      playerATK(0.0f), playerDEF(0.0f), playerDodge(0.0f),
      playerHP(50.0f), playerMAXHP(50.0f),
      hasWeapon(false),
      battlesFought(0), battlesWon(0), damageDealt(0), damageTaken(0),
      Inventory()
{
}

// =========================================================
// Inventory
// =========================================================

void PlayerClasses::addItem(Items item) {
    Inventory.push_back(item);
}

void PlayerClasses::printInventory() {
    if (Inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
        return;
    }

    for (size_t i = 0; i < Inventory.size(); ++i) {
        std::cout << i << ". " << Inventory[i].getName() << std::endl;
    }
}

// =========================================================
// Setters / Getters
// =========================================================

void PlayerClasses::setPlayerName(std::string inputName) { playerName = inputName; }
const std::string PlayerClasses::getPlayerName() { return playerName; }

void PlayerClasses::setPlayerType(char inputType) {
    if (inputType == 'M') playerType = "Mage";
    else if (inputType == 'R') playerType = "Rogue";
    else if (inputType == 'W') playerType = "Warrior";
}

const std::string PlayerClasses::getPlayerType() { return playerType; }

void PlayerClasses::setHasWeapon(bool weaponHave) { hasWeapon = weaponHave; }

void PlayerClasses::setPlayerATK(float inputATK) { playerATK = inputATK; }
float PlayerClasses::getPlayerATK() { return playerATK; }

void PlayerClasses::setPlayerDEF(float inputDEF) { playerDEF = inputDEF; }
float PlayerClasses::getPlayerDEF() { return playerDEF; }

void PlayerClasses::setPlayerDodge(float inputDodge) { playerDodge = inputDodge; }
float PlayerClasses::getPlayerDodge() { return playerDodge; }

void PlayerClasses::setPlayerMAXHP(float inputMAXHP) { playerMAXHP = inputMAXHP; }
float PlayerClasses::getPlayerMAXHP() { return playerMAXHP; }

void PlayerClasses::setPlayerHP(float inputHP) {
    // HP always stays between 0 and maxHP
    playerHP = std::min(playerMAXHP, std::max(0.0f, inputHP));
}

float PlayerClasses::getPlayerHP() { return playerHP; }

int PlayerClasses::getPlayerLevel() { return playerLVL; }

// =========================================================
// EXP + Level Up System
// =========================================================

void PlayerClasses::addEXP(float inputEXP) {
    playerEXPTracker += inputEXP;
    levelUp();
}

void PlayerClasses::levelUp() {
    int newLevel = 1;

    if (playerEXPTracker >= 500.0f)      newLevel = 5;
    else if (playerEXPTracker >= 250.0f) newLevel = 4;
    else if (playerEXPTracker >= 100.0f) newLevel = 3;
    else if (playerEXPTracker >= 50.0f)  newLevel = 2;

    if (newLevel > playerLVL) {
        playerLVL = newLevel;

        // Reset stats to a clean formula (prevents compounding errors)
        playerATK    = 10.0f * newLevel;
        playerDEF    = 5.0f  * newLevel;
        playerDodge  = 5.0f  * newLevel;
        playerMAXHP  = 50.0f * newLevel;
        playerHP     = playerMAXHP;  // full heal on level-up

        std::cout << "You leveled up to LVL " << newLevel << "!\n\n";
    }
}

// =========================================================
// Stats printing
// =========================================================

void PlayerClasses::printStats() const {
    std::cout << "===== PLAYER STATS =====\n";
    std::cout << "Name: " << playerName << "\n";
    std::cout << "Class: " << playerType << "\n";
    std::cout << "Level: " << playerLVL << "\n";
    std::cout << "HP: " << playerHP << "/" << playerMAXHP << "\n";
    std::cout << "ATK: " << playerATK << "\n";
    std::cout << "DEF: " << playerDEF << "\n";
    std::cout << "Dodge: " << playerDodge << "\n";
    std::cout << "========================\n";
}
