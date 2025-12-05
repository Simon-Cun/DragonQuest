#pragma once
#include "Items.h"
#include <string>
#include <vector>

class PlayerClasses {
 protected:
    std::string playerName;
    std::string playerType;
    std::vector<Items> Inventory;
    int playerLVL;
    float playerEXPTracker;
    float playerATK;
    float playerDEF;
    float playerDodge;
    float playerHP;
    float playerMAXHP;
    bool hasWeapon;
    int battlesFought;
   int battlesWon;
   int damageDealt;
   int damageTaken;

 public:
    PlayerClasses();
    void addItem(Items);
    void printInventory();
    void setPlayerName(std::string inputName);
    const std::string getPlayerName();
    void setPlayerType(char inputType);
    const std::string getPlayerType();
    void addEXP(float inputEXP);
    void levelUp();
    void setHasWeapon(bool);
    int getPlayerLevel();
    void setPlayerATK(float inputATK);
    float getPlayerATK();
    void setPlayerDEF(float inputDEF);
    float getPlayerDEF();
    void setPlayerMAXHP(float inputMAXHP);
    float getPlayerMAXHP();
    void setPlayerDodge(float inputDodge);
    float getPlayerDodge();
    void setPlayerHP(float inputHP);
    float getPlayerHP();
    void printStats() const;
};

