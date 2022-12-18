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
    int rankCounter{Card::TWO};
    int suitCounter{Card::CLUB};

    int index{0};
    for (int suit{0}; suit < Card::MAX_SUIT; ++suit) {
        for (int rank{0}; rank < Card::MAX_RANK; ++rank) {
            cardDeck[index++] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
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
    std::cout << '\t';
    for (int i{1}; i <= 52; ++i) {
        cardDeck[i - 1].print();
        std::cout << ' ';
        if (i % 13 == 0) std::cout << "\n\t";
    }
}
