#include "Enemy.h"


Enemy::Enemy() 
: attackStat(0), defenseStat(0), healthStat(100), expDrop(100), runChance(0.05), dropChance(0.05) {}

Enemy::~Enemy() {
    // N/A
}

void Enemy::setDropChance(float stat) {
    dropChance = stat;
}

float Enemy::calcAttackDamage(float oppDefense) {
    const float modifier = 0.5;
    float reduction = oppDefense * modifier;
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
