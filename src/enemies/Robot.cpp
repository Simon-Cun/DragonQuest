#include "Robot.h"

Robot::Robot() {
    setEnemyType("Robot");
    setAttackStat(22.0);
    setDefenseStat(15.0);
    setHealthStat(100.0);
    setRunChance(0.05);
    setExpDrop(50.0);
}