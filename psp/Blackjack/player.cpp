#include <iostream>

#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"

// BasePlayer class method to draw cards from deck
void BasePlayer::drawCard(Deck& cardDeck, int index) {
    std::cout << "Card: ";
    cardDeck[index].print();
    std::cout << ", Points: " << getPoints(cardDeck[index], m_score);
    m_score += getPoints(cardDeck[index], m_score);
    std::cout << " Score: " << m_score << "\n";
}

int BasePlayer::score() {
    return m_score;
}