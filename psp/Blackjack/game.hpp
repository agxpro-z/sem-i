#ifndef GAME_H
#define GAME_H

#include "array.hpp"
#include "card.hpp"

/*
 * enum class for result
 */
enum class Winner {
    PLAYER,
    DEALER,
    DRAW,
};

// Returns card points
int getPoints(const Card& card, int score);

/*
 * Blackjack game
 */
Winner playBlackjack(array<Card, 52>& cardDeck);

/*
 * Game menu
 */
void startGame();

#endif
