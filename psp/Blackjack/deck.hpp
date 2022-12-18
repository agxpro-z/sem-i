#ifndef DECK_H
#define DECK_H

#include <array>

#include "card.hpp"

/*
 * Create Card Deck
 *
 * Takes Card array and assignes card values to all
 */
std::array<Card, 52> creatDeck();

/*
 * Shuffle card deck
 *
 * Shuffles deck of card using mt19937 random function
 */
void shuffleDeck(std::array<Card, 52>& cardDeck);

/*
 * Print all cards numbers of the deck
 */
void printDeck(const std::array<Card, 52>& cardDeck);

#endif
