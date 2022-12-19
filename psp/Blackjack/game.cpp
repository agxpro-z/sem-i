#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "extra.hpp"
#include "game.hpp"
#include "player.hpp"

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

    Player player;
    Dealer dealer;

    // Distribute one card to dealer and two to player
    std::cout << "\nPlayer's ";
    player.drawCard(cardDeck, deckIndex++);
    std::cout << "Dealer's ";
    dealer.drawCard(cardDeck, deckIndex++);
    std::cout << "Player's ";
    player.drawCard(cardDeck, deckIndex++);

    // Display score
    std::cout << "\nPlayer Score: " << player.score() << '\n';
    std::cout << "Dealer Score: " << dealer.score() << '\n';

    // Player's turn
    char ch_p{};
    while (true) {
        std::cout << "\nPlayer's turn, (h)it or (s)tand: ";
        std::cin >> ch_p;
        switch (ch_p) {
            case 'h':
            case 'H':
                player.drawCard(cardDeck, deckIndex++);
                if (player.score() > 21 ) {
                    std::cout << "\nPlayer Score: " << player.score() << '\n';
                    std::cout << "Dealer Score: " << dealer.score() << '\n';
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
    std::cout << "Player points: " << player.score() << '\n';

    // Dealer's turn
    char ch_d{};
    while (true) {
        std::cout << "\nDealer's turn, (h)it to draw cards: ";
        std::cin >> ch_d;
        if (ch_d == 'h' || ch_d == 'H') {
            dealer.drawCard(cardDeck, deckIndex++);
            if (dealer.score() >= 17 && dealer.score() <= 21 ) {
                std::cout << "\nPlayer Score: " << player.score() << '\n';
                std::cout << "Dealer Score: " << dealer.score() << '\n';
                if (dealer.score() > player.score()) return Winner::DEALER;
                else if (dealer.score() == player.score()) return Winner::DRAW;
                else return Winner::PLAYER;
            } else if (dealer.score() > 21) {
                std::cout << "\nPlayer Score: " << player.score() << '\n';
                std::cout << "Dealer Score: " << dealer.score() << '\n';
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
