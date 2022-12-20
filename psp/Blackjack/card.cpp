#include <iostream>

#include "card.hpp"

/*
 * Print Card
 */
void Card::print() const {
    // Print card rank
    std::cout << RANK[cardRank];

    // Print card suit
    std::cout << SUIT[cardSuit];
}

/*
 * Return card value
 */
int Card::value() const {
    switch (cardRank) {
        case ACE:
            return 1;
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
        case SIX:
        case SEVEN:
        case EIGHT:
        case NINE:
        case TEN:
            return cardRank + 1;
        case JACK:
        case KING:
        case QUEEN:
            return 10;
    }
    return 0;
}
