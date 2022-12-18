#include <iostream>

#include "card.hpp"

/*
 * Identifies and prints card numbers and suits
 */
void printCard (const Card& card) {
    using rank = CardRank;
    using suit = CardSuit;

    /* Check and print card rank*/
    switch (card.cardRank) {
        case rank::TWO:
            std::cout << '2';
            break;
        case rank::THREE:
            std::cout << '3';
            break;
        case rank::FOUR:
            std::cout << '4';
            break;
        case rank::FIVE:
            std::cout << '5';
            break;
        case rank::SIX:
            std::cout << '6';
            break;
        case rank::SEVEN:
            std::cout << '7';
            break;
        case rank::EIGHT:
            std::cout << '8';
            break;
        case rank::NINE:
            std::cout << '9';
            break;
        case rank::TEN:
            std::cout << 'T';
            break;
        case rank::JACK:
            std::cout << 'J';
            break;
        case rank::QUEEN:
            std::cout << 'Q';
            break;
        case rank::KING:
            std::cout << 'K';
            break;
        case rank::ACE:
            std::cout << 'A';
            break;
    }

    /* Check and print card suit */
    switch (card.cardSuit) {
        case suit::CLUB:
            std::cout << 'C';
            break;
        case suit::DIAMOND:
            std::cout << 'D';
            break;
        case suit::HEART:
            std::cout << 'H';
            break;
        case suit::SPADE:
            std::cout << 'S';
            break;
    }
}

/*
 * returns card number of given card type
 */
int cardValue(const Card& card) {
    if (card.cardRank <= CardRank::TEN) {
        return int(card.cardRank) + 2;
    }

    switch (card.cardRank) {
        case CardRank::JACK:
        case CardRank::QUEEN:
        case CardRank::KING:
            return 10;
        case CardRank::ACE:
            return 11;
    }
    return 0;
}
