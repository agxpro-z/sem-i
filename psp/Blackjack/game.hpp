#ifndef GAME_H
#define GAME_H

#include "array.hpp"
#include "card.hpp"
#include "player.hpp"

/*
 * enum class for result
 */
enum class Winner {
    PLAYER,
    DEALER,
    DRAW,
};

/*
 * Outcome struct
 */
struct Outcome {
    Winner w{};
    BasePlayer* p{};
};

/*
 * Blackjack game
 */
void playBlackjack(array<Card, 52>& cardDeck);

// Returns card points
int getPoints(const Card& card, int score);

/*
 * Display game outcome
 */
void outcome(Outcome o);

/*
 * Game menu
 */
void startGame();

#endif
