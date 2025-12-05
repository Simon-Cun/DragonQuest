#include "BattleTime.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

BattleTime::BattleTime() : isBlocking(false) {}

void BattleTime::startBattle(PlayerClasses& player, Enemy& enemy) {
    cout << "A " << enemy.getEnemyType() << " DEF enemy appears!\n";

    while (player.getPlayerHP() > 0 && enemy.getHealthStat() > 0) {

        displayBattleMenu(player, enemy);
        playerTurn(player, enemy);

        if (enemy.getHealthStat() <= 0) {
            cout << "Enemy defeated!\n";
            return;
        }

        enemyTurn(player, enemy);
    }

    if (player.getPlayerHP() <= 0) {
        cout << "You were defeated...\n";
    }

    player.addEXP(enemy.getExpDrop());
}

void BattleTime::displayBattleMenu(PlayerClasses& player, Enemy& enemy) {
    cout << "\n========== BATTLE ==========\n";
    cout << "Your HP: " << player.getPlayerHP() << "\n";
    cout << enemy.getEnemyType() << " HP: " << enemy.getHealthStat() << "\n\n";
    cout << "[A] Attack\n";
    cout << "[H] Heal\n";
    cout << "[D] Defend (block half damage)\n";
    cout << "[R] Run\n";
    cout << "Choose action: ";
}

void BattleTime::playerTurn(PlayerClasses& player, Enemy& enemy) {
    char choice;
    cin >> choice;
    choice = toupper(choice);

    switch (choice) {
        case 'A': handleAttack(player, enemy); break;
        case 'H': handleHeal(player); break;
        case 'D': handleDefend(player); break;
        case 'R':
            if (handleRun(player, enemy)) {
                enemy.setHealthStat(0); 
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

void BattleTime::handleAttack(PlayerClasses& player, Enemy& enemy) {
    float rawDamage = player.getPlayerATK() - enemy.getDefenseStat();

    if (rawDamage < 1) rawDamage = 1; 

    enemy.setHealthStat(enemy.getHealthStat() - rawDamage);

    cout << "You dealt " << rawDamage << " damage!\n";
}

void BattleTime::handleHeal(PlayerClasses& player) {
    const float healAmount = 20.0f;

    player.setPlayerHP(player.getPlayerHP() + healAmount);

    cout << "You healed for " << healAmount << " HP!\n";
}

void BattleTime::handleDefend(PlayerClasses& player) {
    isBlocking = true;
    cout << "You brace yourself! You will block half of the next attack.\n";
}

bool BattleTime::handleRun(PlayerClasses& player, Enemy& enemy) {
    float dodge = player.getPlayerDodge() / 100.0f;
    float enemyFactor = enemy.getRunChance();

    float escapeChance = dodge + enemyFactor;

    if (escapeChance > 0.80f)
        escapeChance = 0.80f;

    float roll = (float) rand() / RAND_MAX;

    if (roll < escapeChance) {
        cout << "You successfully escaped!\n";
        return true;
    }

    cout << "Failed to escape!\n";
    return false;
}

void BattleTime::enemyTurn(PlayerClasses& player, Enemy& enemy) {
    cout << "\nEnemy attacks!\n";

    float dodgeChance = player.getPlayerDodge() / 100.0f;
    float roll = (float) rand() / RAND_MAX;

    if (roll < dodgeChance) {
        cout << "You dodged the attack!\n";
        return;
    }

    float dmg = enemy.calcAttackDamage(player.getPlayerDEF());
    if (dmg < 1) dmg = 1;

    if (isBlocking) {
        dmg /= 2;
        cout << "You blocked half the damage!\n";
        isBlocking = false;
    }

    player.setPlayerHP(player.getPlayerHP() - dmg);

    cout << "Enemy dealt " << dmg << " damage!\n";
}
