#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "deck.hpp"

/*
 * Base class for players
 */
class BasePlayer {
  protected:
    int m_score{};

  public:
    BasePlayer() {}
    virtual void won() = 0;
    void drawCard(Deck& cardDeck, int index);
    int score();
};

// Player class
class Player final : public BasePlayer {
  public:
    Player() {}

    void won() override {
        std::cout << "\n\tPlayer wins.\n\a";
    }
};

// Dealer class
class Dealer final : public BasePlayer {
  public:
    Dealer() {}

    void won() override {
        std::cout << "\n\tDealer wins.\n\a";
    }
};

#endif