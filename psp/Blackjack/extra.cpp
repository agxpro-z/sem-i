#include <iostream>
#include <limits>

#include "extra.hpp"

/*
 * Clear std::cin buffer
 */
void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

// Pause game until enter is pressed
void getKey() {
    std::cout << "\n Press enter to go back to menu.";
    clearInput();
    std::cin.get();
}

/*
 * Print Game Menu
 */
void menu() {
    std::cout << "\n\tWelcome to Blackjack\t\n\n";
    std::cout << "\t  Menu: \n";
    std::cout << "\t    1. Start Game\n";
    std::cout << "\t    2. Print Deck\n";
    std::cout << "\t    3. Suffle Deck\n";
    std::cout << "\t    4. Exit\n";
    std::cout << '\n' << "     Select option: ";
}

// Shuffling text animation
void shufflingAnimation() {
    std::cout << "\nShuffling deck" << std::flush;
    system(SYS_SLEEP);
    std::cout << "\rShuffling deck." << std::flush;
    system(SYS_SLEEP);
    std::cout << "\rShuffling deck.." << std::flush;
    system(SYS_SLEEP);
    std::cout << "\rShuffling deck..." << std::flush;
    system(SYS_SLEEP);
}
