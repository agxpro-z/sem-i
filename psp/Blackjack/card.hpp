#ifndef CARD_H
#define CARD_H

constexpr char RANK[] {"A23456789TJKQ"};
constexpr char SUIT[] {"CDHS"};

/*
 * Card Class
 */
class Card {
  public:
    enum Rank {
        ACE,
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
        KING,
        QUEEN,
        MAX_RANK,
    };

    enum Suit {
        CLUB,
        DIAMOND,
        HEART,
        SPADE,
        MAX_SUIT,
    };

  private:
    Rank cardRank{};
    Suit cardSuit{};

  public:
    Card() = default;
    Card(Rank r, Suit s) : cardRank{r}, cardSuit{s} {}

    void print() const;
    int value() const;
};

#endif
