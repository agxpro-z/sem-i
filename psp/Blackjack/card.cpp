#include <iostream>

#include "card.hpp"

/*
 * Print Card
 */
void Card::print() const {
    using namespace std;

    // Print card rank
    switch (cardRank) {
        case ACE:
            cout << '1';
            break;
        case TWO:
            cout << '2';
            break;
        case THREE:
            cout << '3';
            break;
        case FOUR:
            cout << '4';
            break;
        case FIVE:
            cout << '5';
            break;
        case SIX:
            cout << '6';
            break;
        case SEVEN:
            cout << '7';
            break;
        case EIGHT:
            cout << '8';
            break;
        case NINE:
            cout << '9';
            break;
        case TEN:
            cout << 'T';
            break;
        case JACK:
            cout << 'J';
            break;
        case KING:
            cout << 'K';
            break;
        case QUEEN:
            cout << 'Q';
            break;
    }

    // Print card suit
    switch (cardSuit) {
        case CLUB:
            cout << 'C';
            break;
        case DIAMOND:
            cout << 'D';
            break;
        case HEART:
            cout << 'H';
            break;
        case SPADE:
            cout << 'S';
            break;
    }
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
