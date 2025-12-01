#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>


#include "PlayerClasses.h"
#include "Enemy.h"
#include "BattleTime.h"
#include "Mage.h"
#include "Warrior.h"
#include "Rogue.h"

class GameDriver {
public:
    GameDriver();
    void Menu();   // entry point

private:
    std::unique_ptr<PlayerClasses> player;
    std::string playerName;

    // flow pieces
    void showTitleScreen();
    void showIntroDialogue();
    void choosePlayerName();
    void choosePlayerClass();
    void startFirstBattle();

    // helpers
    std::string getLine();
};

GameDriver::GameDriver() : player(nullptr), playerName("Hero") {}

// read one whole line from stdin
std::string GameDriver::getLine() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

void GameDriver::showTitleScreen() {
    std::cout << "=====================================\n";
    std::cout << "           Dragon Quest++            \n";
    std::cout << "=====================================\n\n";
    std::cout << "Press Enter to Start...";
    (void)getLine();
    std::cout << "\n";
}

void GameDriver::showIntroDialogue() {
    std::cout << "Welcome, traveler.\n\n";
    std::cout << "The land of Far Far Away has fallen under the shadow of a great Dragon.\n";
    std::cout << "Monsters roam the roads and villages live in fear.\n\n";
    std::cout << "Only a true hero can stand against this evil.\n";
    std::cout << "Today, that hero might be you.\n\n";
    std::cout << "Press Enter to continue...";
    (void)getLine();
    std::cout << "\n";
}

void GameDriver::choosePlayerName() {
    std::cout << "First, what is your name, hero?\n";
    std::cout << "Enter your name: ";
    std::string name = getLine();
    if (!name.empty()) {
        playerName = name;
    }
    std::cout << "\nGreetings, " << playerName << ".\n\n";
    std::cout << "Press Enter to choose your class...";
    (void)getLine();
    std::cout << "\n";
}

void GameDriver::choosePlayerClass() {
    std::cout << "Choose your class:\n\n";
    std::cout << "  [1] Mage\n";
    std::cout << "  [2] Warrior\n";
    std::cout << "  [3] Rogue\n\n";

    while (true) {
        std::cout << "Enter 1, 2, or 3: ";
        std::string choice = getLine();

        if (choice == "1") {
            player = std::make_unique<Mage>();
            break;
        } else if (choice == "2") {
            player = std::make_unique<Warrior>();
            break;
        } else if (choice == "3") {
            player = std::make_unique<Rogue>();
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // Your base class API:
    //   void setPlayerName(std::string);
    //   const std::string getPlayerType();
    player->setPlayerName(playerName);

    std::cout << "\nYou have chosen the path of the "
              << player->getPlayerType() << ".\n\n";
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


void GameDriver::Menu() {
    showTitleScreen();
    showIntroDialogue();
    choosePlayerName();
    choosePlayerClass();
    startFirstBattle(); // hands control to BattleTime
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // for rand() in BattleTime
    GameDriver driver;
    driver.Menu();
    return 0;
}
