#include "PlayerClasses.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

PlayerClasses::PlayerClasses() : playerName(""), playerType(""), playerLVL(1), playerEXPTracker(0.0),
                                 playerATK(0.0), playerDEF(0.0), playerDodge(0.0), playerHP(50.0), hasWeapon(false),
                                 battlesFought(0), battlesWon(0), damageDealt(0), damageTaken(0) {}

void PlayerClasses::setPlayerName(std::string inputName) {playerName = inputName;}

const std::string PlayerClasses::getPlayerName() {return playerName;}

void PlayerClasses::setPlayerType(char inputType) {
    if (inputType == 'M') playerType = "Mage";
    else if (inputType == 'R') playerType = "Rogue";
    else if (inputType == 'W') playerType = "Warrior";
}

const std::string PlayerClasses::getPlayerType() {return playerType;}

void PlayerClasses::setHasWeapon(bool weaponHave) {hasWeapon = weaponHave;}


void PlayerClasses::addEXP(float inputEXP) {
    playerEXPTracker += inputEXP;
    levelUp();
}

void PlayerClasses::levelUp() {  //LVL starts at 1, max at LVL 5
    if (playerEXPTracker >= 500.0) {
        if (playerLVL != 2) {
            playerLVL = 5;
            setPlayerATK(playerATK / 4 * 5);
            setPlayerDEF(playerDEF / 4 * 5);
            setPlayerDodge(playerDodge / 4 * 5);
            setPlayerHP(playerHP / 4 * 5);
            setPlayerMAXHP(playerMAXHP / 4 * 5);
            std::cout << "You leveled up to LVL 5!\n\n";
        }
    }

    else if (playerEXPTracker >= 250.0) {
        if (playerLVL != 4) {
            playerLVL = 4;
            setPlayerATK(playerATK / 3 * 4);
            setPlayerDEF(playerDEF / 3 * 4);
            setPlayerDodge(playerDodge / 3 * 4);
            setPlayerHP(playerHP / 3 * 4);
            setPlayerMAXHP(playerMAXHP / 3 * 4);
            std::cout << "You leveled up to LVL 4!\n\n";
        }
    }

    else if (playerEXPTracker >= 100.0) {
        if (playerLVL != 3) {
            playerLVL = 3;
            setPlayerATK(playerATK / 2 * 3);
            setPlayerDEF(playerDEF / 2 * 3);
            setPlayerDodge(playerDodge / 2 * 3);
            setPlayerHP(playerHP / 2 * 3);
            setPlayerMAXHP(playerMAXHP / 2 * 3);
            std::cout << "You leveled up to LVL 3!\n\n";
        }
    }

    else if (playerEXPTracker >= 50.0) {
        if (playerLVL != 2) {
            playerLVL = 2;
            setPlayerATK(playerATK * 2);
            setPlayerDEF(playerDEF * 2);
            setPlayerDodge(playerDodge * 2);
            setPlayerHP(playerHP * 2);
            setPlayerMAXHP(playerMAXHP * 2);
            std::cout << "You leveled up to LVL 2!\n\n";
        }
    }
}

int PlayerClasses::getPlayerLevel() {return playerLVL;}


void PlayerClasses::setPlayerATK(float inputATK) {playerATK = inputATK;}

float PlayerClasses::getPlayerATK() {return playerATK;}

void PlayerClasses::setPlayerMAXHP(float inputMAXHP) {playerMAXHP = inputMAXHP;}

float PlayerClasses::getPlayerMAXHP() {return playerMAXHP;}

void PlayerClasses::setPlayerDEF(float inputDEF) {playerDEF = inputDEF;}

float PlayerClasses::getPlayerDEF() {return playerDEF;}


void PlayerClasses::setPlayerDodge(float inputDodge) {playerDodge = inputDodge;}

float PlayerClasses::getPlayerDodge() {return playerDodge;}


void PlayerClasses::setPlayerHP(float inputHP) {
    playerHP = std::min(playerMAXHP, std::max(0.0f, inputHP));
    // minimum is 0 maximum is maxHP
}

float PlayerClasses::getPlayerHP() {return playerHP;}

void PlayerClasses::printStats() const {
    std::cout << "===== PLAYER STATS =====\n";
    std::cout << "Name: " << playerName << "\n";
    std::cout << "Class: " << playerType << "\n";
    std::cout << "Level: " << playerLVL << "\n";
    std::cout << "HP: " << playerHP << "\n";
    std::cout << "ATK: " << playerATK << "\n";
    std::cout << "DEF: " << playerDEF << "\n";
    std::cout << "Dodge: " << playerDodge << "\n";
    std::cout << "========================\n";
}