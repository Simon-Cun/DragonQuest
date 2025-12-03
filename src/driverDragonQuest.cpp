#include <iostream>
#include <string>
#include <cctype>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "PlayerClasses.h"
#include "Enemy.h"
#include "BattleTime.h"
#include "Mage.h"
#include "Warrior.h"
#include "Rogue.h"

#include "Slime.h"
#include "Goblin.h"
#include "Ogre.h"
#include "Robot.h"
#include "Dragon.h"

class GameDriver {
public:
    GameDriver();
    void Menu();

private:
    PlayerClasses player;
    std::string playerName;

    bool foughtSlime;
    bool foughtGoblin;
    bool foughtOgre;
    bool foughtRobot;

    void showTitleScreen();
    void showIntroDialogue();
    void choosePlayerName();
    void choosePlayerClass();
    void explorationLoop();
    void fightEnemy(Enemy& e);

    std::string getLine();
    int randPercent();
};

GameDriver::GameDriver()
    : player(), playerName("Hero"),
      foughtSlime(false), foughtGoblin(false),
      foughtOgre(false), foughtRobot(false) {}

std::string GameDriver::getLine() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

int GameDriver::randPercent() {
    return rand() % 100;
}

void GameDriver::showTitleScreen() {
    std::cout << "=====================================\n";
    std::cout << "           Dragon Quest++            \n";
    std::cout << "=====================================\n\n";
    std::cout << "Press Enter to Start...";
    getLine();
    std::cout << "\n";
}

void GameDriver::showIntroDialogue() {
    std::cout << "Welcome, traveler.\n\n";
    std::cout << "The land is filled with enemies.\n";
    std::cout << "Defeat all of them to challenge the Dragon.\n\n";
    std::cout << "Press Enter to continue...";
    getLine();
    std::cout << "\n";
}

void GameDriver::choosePlayerName() {
    std::cout << "What is your name?\n";
    std::cout << "Enter your name: ";
    std::string name = getLine();
    if (!name.empty()) playerName = name;

    std::cout << "\nGreetings, " << playerName << ".\n\n";
    std::cout << "Press Enter to choose your class...";
    getLine();
    std::cout << "\n";
}

void GameDriver::choosePlayerClass() {
    std::cout << "Choose your class:\n\n"
              << "  [M] Mage\n"
              << "  [W] Warrior\n"
              << "  [R] Rogue\n\n"
              << "Or view class stats:\n\n"
              << "  [S] Stats\n\n";

    char choice;
    while (true) {
        std::cout << "Enter M, W, R, or S: ";
        std::cin >> choice;
        choice = toupper(choice);

        if (choice != 'M' && choice != 'W' && choice != 'R' && choice != 'S') {
            std::cout << "\nInvalid choice. Enter again \n\n";
        }
        else if (choice == 'M') {
            player = Mage();
            std::cout << "Brave hero, you have chosen the Mystic Mage\n\n";
            break;
        }
        else if (choice == 'W') {
            player = Warrior();
            std::cout << "Brave hero, you have chosen the Weathered Warrior\n\n";
            break;
        }
        else if (choice == 'R') {
            player = Rogue();
            std::cout << "Brave hero, you have chosen the Razorfoot Rogue\n\n";
            break;
        }
        else if (choice == 'S') {
            std::cout << "\n===== MAGE =====      ==== WARRIOR ====      ===== ROGUE =====\n"
                      << "  ATK:    25.0          ATK:     10.0          ATK:     10.0\n"
                      << "  DEF:     5.0          DEF:     25.0          DEF:     10.0\n"
                      << "  Dodge:   5.0          Dodge:    5.0          Dodge:   25.0\n"
                      << "================      =================      =================\n\n";
        }
    }
    player.setPlayerType(choice);
    player.setPlayerName(playerName);

    std::cout << "Your quest awaits. \n\n"
              << "Press Enter to begin your adventure...";
    player->setPlayerName(playerName);

    std::cout << "\nYou chose: " << player->getPlayerType() << "\n\n";
    std::cout << "Press Enter to begin your adventure...";
    (void)getLine();
    std::cout << "\n";
}

void GameDriver::startFirstBattle() {
    std::cout << "You step beyond the safety of the village...\n";
    Slime slime;                // Fully initialized by constructor
    std::cout << "A " << slime.getEnemyType() << " weak monster jumps out from the tall grass!\n\n";
    std::cout << "Press Enter to begin the battle...";
    getLine();
    std::cout << "\n";

    BattleTime battle;          // Uses your default constructor
    battle.startBattle(*player, slime);
    
    std::cout << "\nThe battle has ended.\n";
    std::cout << "Press Enter to exit the game...";
    getLine();
}

void GameDriver::fightEnemy(Enemy& e) {
    BattleTime battle;
    battle.startBattle(player, e);
}

void GameDriver::explorationLoop() {
    std::cout << "Your adventure begins...\n\n";

    while (true) {
        if (foughtSlime && foughtGoblin && foughtOgre && foughtRobot) {
            std::cout << "\nThe ground shakes... The DRAGON approaches!\n";
            Dragon dragon;
            fightEnemy(dragon);
            std::cout << "\nYou defeated the DRAGON! You beat the game!\n";
            return;
        }

        std::cout << "\nMove forward? (Press Enter)";
        getLine();

        int roll = randPercent();

        if (roll < 50) {
            std::cout << "You move forward cautiously... Nothing happens.\n";
        }
        else if (roll < 80) {
            std::cout << "A monster appears!\n";
            if (!foughtSlime) {
                Slime s;
                fightEnemy(s);
                foughtSlime = true;
            }
            else if (!foughtGoblin) {
                Goblin g;
                fightEnemy(g);
                foughtGoblin = true;
            }
            else if (!foughtOgre) {
                Ogre o;
                fightEnemy(o);
                foughtOgre = true;
            }
            else if (!foughtRobot) {
                Robot r;
                fightEnemy(r);
                foughtRobot = true;
            }

            std::cout << "\nEnemy defeated! Continue your journey...\n";
        }
        else {
            std::cout << "You found mysterious loot on the ground!\n";
            std::cout << "(Loot system not implemented yet.)\n";
        }
    }
}

void GameDriver::Menu() {
    showTitleScreen();
    showIntroDialogue();
    choosePlayerName();
    choosePlayerClass();
    explorationLoop();
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    GameDriver driver;
    driver.Menu();
    return 0;
}
