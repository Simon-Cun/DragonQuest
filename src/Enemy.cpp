#include "Enemy.h"


Enemy::Enemy() 
: enemyType("Monster"), attackStat(0), defenseStat(0), healthStat(100), expDrop(100), runChance(0.05), dropChance(0.05) {}

Enemy::~Enemy() {
    // N/A
}

void Enemy::setDropChance(float stat) {
    dropChance = stat;
}

float Enemy::calcAttackDamage(float oppDefense) {
    // float minspread = 0.90;
    // float maxspread = 1.10;
    // float spread = float(rand() / RAND_MAX);
    // spread = minspread + spread * (maxspread - minspread);
    // float basedmg = attackStat * spread;
    // const float scaleconstant = 100.0;

    // float dmgred = oppDefense / (oppDefense + scaleconstant);
    float totalDMG = attackStat - oppDefense;
    if(totalDMG < 0.0) {
        totalDMG = 0.0;
    }
    return totalDMG;
}

void Enemy::setRunChance(float stat) {
    runChance = stat;
}

void Enemy::setHealthStat(float stat) {
    healthStat = stat;
}

void Enemy::setAttackStat(float stat) {
    attackStat = stat;
}

void Enemy::setDefenseStat(float stat) {
    defenseStat = stat;
}

void Enemy::setExpDrop(float stat) {
    expDrop = stat;
}

void Enemy::setEnemyType(const std::string& type) {
    enemyType = type;
}

float Enemy::getAttackStat() {
    return attackStat;
}

float Enemy::getDefenseStat() {
    return defenseStat;
}

float Enemy::getHealthStat() {
    return healthStat;
}

float Enemy::getRunChance() {
    return runChance;
}

float Enemy::getExpDrop() {
    return expDrop;
}

std::string Enemy::getEnemyType() const {
    return enemyType;
}
