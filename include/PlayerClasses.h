#pragma once
#include <string>

class PlayerClasses {
 protected:
    std::string playerName;
    std::string playerType;
    int playerLVL;
    float playerEXPTracker;
    float playerATK;
    float playerDEF;
    float playerDodge;
    float playerHP;
    bool hasWeapon;

 public:
    PlayerClasses();
    void setPlayerName(std::string inputName);
    const std::string getPlayerName();
    void setPlayerType(std::string inputType);
    const std::string getPlayerType();
    void addEXP(float inputEXP);
    void levelUp();
    void setHasWeapon(bool);
    int getPlayerLevel();
    void setPlayerATK(float inputATK);
    float getPlayerATK();
    void setPlayerDEF(float inputDEF);
    float getPlayerDEF();
    void setPlayerDodge(float inputDodge);
    float getPlayerDodge();
    void setPlayerHP(float inputHP);
    float getPlayerHP();
};

