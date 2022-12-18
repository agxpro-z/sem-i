#include <iostream>
#include <limits>

/*
 * Clear std::cin buffer
 */
void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

/*
 * Print welcome message
 */
void printWelcome() {
    std::cout << "\n\tWelcome to Blackjack\t\n\n";
}
