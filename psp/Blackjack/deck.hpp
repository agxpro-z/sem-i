#ifndef DECK_H
#define DECK_H

#include "array.hpp"
#include "card.hpp"

/*
 * Cards deck class
 */
class Deck {
  private:
    array<Card, 52> cardDeck{};

  public:
    Deck();

    /*
     * Shuffle card deck
     *
     * Shuffles deck of card using mt19937 random function
     */
    void shuffle();

    /*
     * Print all cards numbers of the deck
     */
    void print();

    /*
     * Return a card from cardDeck
     */
    const Card& operator[](int n);
};

#endif
