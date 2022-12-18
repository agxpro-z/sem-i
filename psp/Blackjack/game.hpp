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

/*
 * Blackjack game
 */
Winner playBlackjack(array<Card, 52>& cardDeck);

/*
 * Game menu
 */
void startGame();

#endif
