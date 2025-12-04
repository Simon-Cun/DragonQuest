#pragma once
#include <string>

class Enemy {
    protected:
        std::string enemyType;
        float attackStat;
        float defenseStat;
        float expDrop;
        float healthStat;
        float runChance;
        float dropChance;
    public:
        Enemy();
        ~Enemy();
        void setAttackStat(float);
        void setDefenseStat(float);
        void setExpDrop(float);
        void setHealthStat(float);
        void setRunChance(float);
        void setEnemyType(const std::string&);
        void setDropChance(float);
        float calcAttackDamage(float);

        float getAttackStat();
        float getDefenseStat();
        float getExpDrop();
        float getHealthStat();
        float getRunChance();
        std::string getEnemyType() const;

};