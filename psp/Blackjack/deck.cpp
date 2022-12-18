#include <array>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

#include "card.hpp"

/*
 * Create and assign card numbers to all cards
 */
std::array<Card, 52> creatDeck() {
    std::array<Card, 52> cardDeck{};
    int rankCounter{(int)CardRank::TWO};
    int suitCounter{(int)CardSuit::CLUB};

    for (auto& c : cardDeck) {
        c.cardRank = (CardRank)rankCounter;
        c.cardSuit = (CardSuit)suitCounter;

        if (rankCounter == (int)CardRank::ACE) {
            ++suitCounter;
            rankCounter = (int)CardRank::TWO;
        } else {
            ++rankCounter;
        }
    }
    return cardDeck;
}

/*
 * Shuffle cards of the deck ramdomly
 */
void shuffleDeck(std::array<Card, 52>& cardDeck) {
    // mt is static so it only gets seeded once
    static std::mt19937 mt{std::mt19937::result_type(std::time(nullptr))};
    std::shuffle(cardDeck.begin(), cardDeck.end(), mt);
}

/*
 * Print all cards of the deck
 */
void printDeck(const std::array<Card, 52>& cardDeck) {
    int counter {(int)CardRank::TWO};
    for (const Card& c : cardDeck) {
        if (counter == (int)CardRank::TWO) std::cout << '\t';
        printCard(c);
        std::cout << ' ';
        if (!(counter < (int)CardRank::ACE)) {
            std::cout << '\n';
            counter = (int)CardRank::TWO;
        } else {
            ++counter;
        }
    }
    std::cout << '\n';
}
