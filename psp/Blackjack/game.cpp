#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "extra.hpp"
#include "game.hpp"

// Returns card points
int getPoints(const Card& card, int score) {
    // Return 11 score for Ace if score is below 10
    if (score <= 10 and card.value() == 1)
        return 11;
    else
        return card.value();
}

/*
 * Blackjack game
 */
Winner playBlackjack(Deck& cardDeck) {

    // Card drawing index
    int deckIndex{0};

    // Give one card to dealer and two to player
    int playerPoints{cardDeck[deckIndex++].value()};
    int dealerPoints{cardDeck[deckIndex++].value()};
    playerPoints += getPoints(cardDeck[deckIndex++], playerPoints);

    // Display score
    std::cout << "\nPlayer Score: " << playerPoints << '\n';
    std::cout << "Dealer Score: " << dealerPoints << '\n';

    // Player's turn
    char ch_p{};
    while (true) {
        std::cout << "\nPlayer's turn, (h)it or (s)tand: ";
        std::cin >> ch_p;
        switch (ch_p) {
            case 'h':
            case 'H':
                std::cout << "Player Card: ";
                cardDeck[deckIndex].print();
                std::cout << ", Points: " << getPoints(cardDeck[deckIndex], playerPoints);
                playerPoints += getPoints(cardDeck[deckIndex], playerPoints);
                std::cout << " Score: " << playerPoints << "\n";
                ++deckIndex;
                if (playerPoints > 21 ) {
                    std::cout << "\nPlayer Score: " << playerPoints << '\n';
                    std::cout << "Dealer Score: " << dealerPoints << '\n';
                    return Winner::DEALER;
                }
                break;
            case 's':
            case 'S':
                goto dealer;
                break;
            default:
                std::cout << "Invalid input, try again\n";
        }
        clearInput();
    }

dealer:
    std::cout << "Player points: " << playerPoints << '\n';

    // Dealer's turn
    char ch_d{};
    while (true) {
        std::cout << "\nDealer's turn, (h)it to draw cards: ";
        std::cin >> ch_d;
        if (ch_d == 'h' || ch_d == 'H') {
            std::cout << "Dealer card: ";
            cardDeck[deckIndex].print();
            std::cout << ", Points: " << getPoints(cardDeck[deckIndex], dealerPoints);
            dealerPoints += getPoints(cardDeck[deckIndex], dealerPoints);
            std::cout << " Score: " << dealerPoints << "\n";
            ++deckIndex;

            if (dealerPoints >= 17 && dealerPoints <= 21 ) {
                std::cout << "\nPlayer Score: " << playerPoints << '\n';
                std::cout << "Dealer Score: " << dealerPoints << '\n';
                if (dealerPoints > playerPoints) return Winner::DEALER;
                else if (dealerPoints == playerPoints) return Winner::DRAW;
                else return Winner::PLAYER;
            } else if (dealerPoints > 21) {
                std::cout << "\nPlayer Score: " << playerPoints << '\n';
                std::cout << "Dealer Score: " << dealerPoints << '\n';
                return Winner::PLAYER;
            }
        } else {
                std::cout << "Invalid input, try again\n";
        }
        clearInput();
    }

    return Winner::DRAW;
}

// Pause game until enter is pressed
void getKey() {
    std::cout << "\n Press enter to go back to menu.";
    clearInput();
    std::cin.get();
}

/*
 * Display game outcome
 */
void outcome(Winner w) {
    switch (w) {
        case Winner::PLAYER:
            std::cout << "\n\tPlayer wins.\n\a";
            getKey();
            break;
        case Winner::DEALER:
            std::cout << "\n\tDealer wins.\n\a";
            getKey();
            break;
        case Winner::DRAW:
        default:
            std::cout << "\n\tDraw.\n\a";
            getKey();
            break;
    }
}

/*
 * Game
 */
void startGame() {
    // Create cards deck
    Deck cardDeck;

    char gameVar{};

    while (true) {
        menu();
        std::cin >> gameVar;

        switch (gameVar) {
            case '1':
                cardDeck.shuffle();
                outcome(playBlackjack(cardDeck));
                std::cout << "\n\n";
                break;
            case '2':
                std::cout << '\n';
                cardDeck.print();
                std::cout << '\n';
                break;
            case '3':
                std::cout << "\nShuffling deck...\n";
                cardDeck.shuffle();
                std::cout << "\n\n";
                break;
            case '4':
                std::cout << "\n\tThank you for playing Blackjack\n";
                return;
            default:
                std::cout << "Invalid option, choose again.\n\n";
                clearInput();
                break;
        }
    }
}
