#include <algorithm>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

#include "card.hpp"
#include "deck.hpp"

/*
 * Create and assign card numbers to all cards
 */
Deck::Deck() {
    int index{0};
    for (int suit{0}; suit < Card::MAX_SUIT; ++suit) {
        for (int rank{0}; rank < Card::MAX_RANK; ++rank) {
            cardDeck[index++] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
        }
    }
}

/*
 * Shuffle cards of the deck ramdomly
 */
void Deck::shuffle() {
    // mt is static so it only gets seeded once
    static std::mt19937 mt{std::mt19937::result_type(std::time(nullptr))};
    std::shuffle(cardDeck.begin(), cardDeck.end(), mt);
}

/*
 * Print all cards of the deck
 */
void Deck::print() {
    std::cout << '\t';
    for (int i{1}; i <= 52; ++i) {
        cardDeck[i - 1].print();
        std::cout << ' ';
        if (i % 13 == 0) std::cout << "\n\t";
    }
}

/*
 * Return a card from deck
 */
const Card& Deck::operator[](int n) {
    return cardDeck[n];
}
