#include "../header/PlayerClasses.h"
#include <iostream>
#include <string>
#include <stdexcept>

PlayerClasses::PlayerClasses() : playerName(""), playerType(""), playerLVL(1), playerEXPTracker(0.0),
                                 playerATK(0.0), playerDEF(0.0), playerDodge(0.0), playerHP(50.0) {}

void PlayerClasses::setPlayerName(std::string inputName) {playerName = inputName;}

const std::string PlayerClasses::getPlayerName() {return playerName;}

void PlayerClasses::setPlayerType(std::string inputType) {
    if (inputType != "M" && inputType != "R" && inputType != "W") throw std::runtime_error("Invalid Type");
    
    if (inputType == "M") playerType = "MAGE";
    else if (inputType == "R") playerType = "ROGUE";
    else if (inputType == "W") playerType = "WARRIOR";
}

const std::string PlayerClasses::getPlayerType() {return playerType;}


void PlayerClasses::addEXP(float inputEXP) {playerEXPTracker += inputEXP;}

void PlayerClasses::levelUp() {  //LVL starts at 1, max at LVL 5
    if (playerEXPTracker >= 500.0) {
        if (playerLVL != 2) {
            playerLVL = 5;
            setPlayerATK(playerATK / 4 * 5);
            setPlayerDEF(playerDEF / 4 * 5);
            setPlayerDodge(playerDodge / 4 * 5);
            setPlayerHP(playerHP / 4 * 5);
        }
    }

    else if (playerEXPTracker >= 250.0) {
        if (playerLVL != 4) {
            playerLVL = 4;
            setPlayerATK(playerATK / 3 * 4);
            setPlayerDEF(playerDEF / 3 * 4);
            setPlayerDodge(playerDodge / 3 * 4);
            setPlayerHP(playerHP / 3 * 4);
        }
    }

    else if (playerEXPTracker >= 100.0) {
        if (playerLVL != 3) {
            playerLVL = 3;
            setPlayerATK(playerATK / 2 * 3);
            setPlayerDEF(playerDEF / 2 * 3);
            setPlayerDodge(playerDodge / 2 * 3);
            setPlayerHP(playerHP / 2 * 3);
        }
    }

    else if (playerEXPTracker >= 50.0) {
        if (playerLVL != 2) {
            playerLVL = 2;
            setPlayerATK(playerATK * 2);
            setPlayerDEF(playerDEF * 2);
            setPlayerDodge(playerDodge * 2);
            setPlayerHP(playerHP * 2);
        }
    }
}

int PlayerClasses::getPlayerLevel() {return playerLVL;}


void PlayerClasses::setPlayerATK(float inputATK) {playerATK = inputATK;}

float PlayerClasses::getPlayerATK() {return playerATK;}


void PlayerClasses::setPlayerDEF(float inputDEF) {playerDEF = inputDEF;}

float PlayerClasses::getPlayerDEF() {return playerDEF;}


void PlayerClasses::setPlayerDodge(float inputDodge) {playerDodge = inputDodge;}

float PlayerClasses::getPlayerDodge() {return playerDodge;}


void PlayerClasses::setPlayerHP(float inputHP) {playerHP = inputHP;}

float PlayerClasses::getPlayerHP() {return playerHP;}
