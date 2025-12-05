#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <limits>

#include "GameDriver.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    char again = 'Y';
    do {
        GameDriver driver;
        driver.Menu();

        std::cout << "\nPlay Again? (Y/N): ";
        std::cin >> again;
        again = static_cast<char>(std::toupper(again));

        // Clear input buffer for any later getline calls
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (again == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
