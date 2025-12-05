#include "GameDriver.h"

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

using std::cout;
using std::cin;

GameDriver::GameDriver()
    : player(),
      playerName("Hero"),
      dragonsbane(),
      frostforged(),
      thunderfury(),
      obsidiansentinel(),
      lesserhealthpotion(),
      greaterhealthpotion(),
      foughtSlime(false),
      foughtGoblin(false),
      foughtOgre(false),
      foughtRobot(false) {}

std::string GameDriver::getLine() {
    std::string s;
    std::getline(cin, s);
    return s;
}

int GameDriver::randPercent() {
    return std::rand() % 100;
}

void GameDriver::showTitleScreen() {
    cout << "=====================================\n";
    cout << "           Dragon Quest++            \n";
    cout << "=====================================\n\n";
    cout << "Press Enter to Start...";
    getLine();
    cout << "\n";
}

void GameDriver::showIntroDialogue() {
    cout << "Welcome, traveler.\n\n";
    cout << "The land is filled with enemies.\n";
    cout << "Defeat all of them to challenge the Dragon.\n\n";
    cout << "Press Enter to continue...";
    getLine();
    cout << "\n";
}

void GameDriver::choosePlayerName() {
    cout << "What is your name?\n";
    cout << "Enter your name: ";
    std::string name = getLine();
    if (!name.empty()) playerName = name;

    cout << "\nGreetings, " << playerName << ".\n\n";
    cout << "Press Enter to choose your class...";
    getLine();
    cout << "\n";
}

void GameDriver::choosePlayerClass() {
    cout << "Choose your class:\n\n"
         << "  [M] Mage\n"
         << "  [W] Warrior\n"
         << "  [R] Rogue\n\n"
         << "Or view class stats:\n\n"
         << "  [S] Stats\n\n";

    char choice;
    while (true) {
        cout << "Enter M, W, R, or S: ";
        cin >> choice;
        choice = static_cast<char>(std::toupper(choice));

        if (choice != 'M' && choice != 'W' && choice != 'R' && choice != 'S') {
            cout << "\nInvalid choice. Enter again \n\n";
        }
        else if (choice == 'M') {
            player = Mage();
            cout << "Brave hero, you have chosen the Mystic Mage\n\n";
            break;
        }
        else if (choice == 'W') {
            player = Warrior();
            cout << "Brave hero, you have chosen the Weathered Warrior\n\n";
            break;
        }
        else if (choice == 'R') {
            player = Rogue();
            cout << "Brave hero, you have chosen the Razorfoot Rogue\n\n";
            break;
        }
        else if (choice == 'S') {
            cout << "\n===== MAGE =====      ==== WARRIOR ====      ===== ROGUE =====\n"
                 << "  ATK:    25.0          ATK:     10.0          ATK:     10.0\n"
                 << "  DEF:     5.0          DEF:     25.0          DEF:     10.0\n"
                 << "  Dodge:   5.0          Dodge:    5.0          Dodge:   25.0\n"
                 << "================      =================      =================\n\n";
        }
    }

    // Clear leftover newline for later getline calls
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    player.setPlayerType(choice);
    player.setPlayerName(playerName);

    cout << "Your quest awaits. \n\n"
         << "Press Enter to begin your adventure...";
    (void)getLine();
    cout << "\n";
}

void GameDriver::fightEnemy(Enemy& e) {
    BattleTime battle;
    battle.startBattle(player, e);
}

void GameDriver::startFirstBattle() {
    cout << "You step beyond the safety of the village...\n";
    Slime slime;
    cout << "A " << slime.getEnemyType()
         << " weak monster jumps out from the tall grass!\n\n";
    cout << "Press Enter to begin the battle...";
    getLine();
    cout << "\n";

    BattleTime battle;
    battle.startBattle(player, slime);

    cout << "\nThe battle has ended.\n";
}

void GameDriver::explorationLoop() {
    cout << "Your adventure begins...\n\n";

    while (true) {

        // GLOBAL DEATH CHECK – if player is dead, end the game immediately
        if (player.getPlayerHP() <= 0.0f) {
            cout << "\nYou have been defeated. Game Over.\n";
            return; 
        }

        // If all enemies are defeated → Dragon fight
        if (foughtSlime && foughtGoblin && foughtOgre && foughtRobot) {
            cout << "\nThe ground shakes... The DRAGON approaches!\n";
            Dragon dragon;
            fightEnemy(dragon);

            // FINAL death check after Dragon fight
            if (player.getPlayerHP() <= 0.0f) {
                cout << "\nYou fought bravely, but fell in battle...\n";
                return;
            }

            cout << "\nYou defeated the DRAGON! You beat the game!\n";
            return;
        }

        cout << "\nMove forward? (Press Enter)";
        getLine();

        int roll = randPercent();

        if (roll < 50) {
            cout << "You move forward cautiously... Nothing happens.\n";
        }
        else if (roll < 80) {
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

            // CRITICAL DEATH CHECK AFTER ANY BATTLE
            if (player.getPlayerHP() <= 0.0f) {
                cout << "\nYou have been defeated. Game Over.\n";
                return;  
            }
        }
        else {
            cout << "You found mysterious loot on the ground!\n";
            int randNum = randPercent();

            if (randNum < 20)               player.addItem(dragonsbane);
            else if (randNum < 40)          player.addItem(frostforged);
            else if (randNum < 65)          player.addItem(lesserhealthpotion);
            else if (randNum < 70)          player.addItem(greaterhealthpotion);
            else if (randNum < 85)          player.addItem(thunderfury);
            else                             player.addItem(obsidiansentinel);
        }
    }
}

void GameDriver::Menu() {
    showTitleScreen();
    showIntroDialogue();
    choosePlayerName();
    choosePlayerClass();
    startFirstBattle();
    if (player.getPlayerHP() > 0.0f) {
        explorationLoop();
    }
}
