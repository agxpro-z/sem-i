#ifndef CARD_H
#define CARD_H

/*
 * Enum of card ranks
 */
enum class CardRank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    MAX_RANK,
};

/*
 * Enum of card suits
 */
enum class CardSuit {
    CLUB,
    DIAMOND,
    HEART,
    SPADE,
    MAX_SUIT,
};

/*
 * Card structure
 */
struct Card {
    CardRank cardRank{};
    CardSuit cardSuit{};
};

/*
 * Identifies and prints card numbers and suits
 */
void printCard(const Card& card);

/*
 * Returns card number of given card type
 */
int cardValue(const Card& card);

#endif
