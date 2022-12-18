#include <array>
#include <iostream>
#include "card.hpp"
#include "deck.hpp"
#include "extra.hpp"
#include "game.hpp"

/*
 * Blackjack game
 */
Winner playBlackjack(std::array<Card, 52>& cardDeck) {

    int deckIndex{ 0 };

    int dealerPoints{ cardValue(cardDeck[deckIndex]) };
    ++deckIndex;
    int playerPoints{ cardValue(cardDeck[deckIndex]) };
    ++deckIndex;
    playerPoints += cardValue(cardDeck[deckIndex]);
    ++deckIndex;

    std::cout << "\nPlayer Score: " << playerPoints << '\n';
    std::cout << "Dealer Score: " << dealerPoints << '\n';

    char ch_p{};
    while (true) {
        std::cout << "\nPlayer's turn, hit(h) or stand(s): ";
        std::cin >> ch_p;
        switch (ch_p) {
            case 'h':
            case 'H':
                std::cout << "Player Card: ";
                printCard(cardDeck[deckIndex]);
                playerPoints += cardValue(cardDeck[deckIndex]);
                std::cout << ", Points: " << cardValue(cardDeck[deckIndex])
                        << " Score: " << playerPoints << "\n";
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
    };

dealer:
    std::cout << "Player points: " << playerPoints << '\n';

    char ch_d{};
    while (true) {
        std::cout << "\nDealer's turn, hit(h) to draw cards: ";
        std::cin >> ch_d;
        if (ch_d == 'h' || ch_d == 'H') {
            std::cout << "Dealer card: ";
            printCard(cardDeck[deckIndex]);
            dealerPoints += cardValue(cardDeck[deckIndex]);
            std::cout << ", Points: " << cardValue(cardDeck[deckIndex])
                    << " Score: " << dealerPoints << "\n";
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
    };

    return Winner::DRAW;
}

/*
 * Game menu
 */
void startGame() {

newGame:
    printWelcome();
    std::array<Card, 52> cardDeck{ creatDeck() };
    int gameVar{};

    while (true) {
        std::cout << "\t  Menu: \n";
        std::cout << "\t    1. Start Game\n";
        std::cout << "\t    2. Start New\n";
        std::cout << "\t    3. Print Deck\n";
        std::cout << "\t    4. Suffle Deck\n";
        std::cout << "\t    5. Exit\n";
        std::cout << '\n' << "     Enter number of the option: ";
        std::cin >> gameVar;

        switch (gameVar) {
            case 1:
                shuffleDeck(cardDeck);
                switch (playBlackjack(cardDeck)) {
                    char ch;
                    case Winner::PLAYER:
                        std::cout << "\n\tPlayer wins.\n\a";
                        std::cout << "\n Press any key to go back to menu.";
                        clearInput();
                        std::cin >> ch;
                        break;
                    case Winner::DEALER:
                        std::cout << "\n\tDealer wins.\n\a";
                        std::cout << "\n Press any key to go back to menu.";
                        clearInput();
                        std::cin >> ch;
                        break;
                    case Winner::DRAW:
                    default:
                        std::cout << "\n\tDraw.\n\a";
                        std::cout << "\n Press any key to go back to menu.";
                        clearInput();
                        std::cin >> ch;
                        break;
                }
                std::cout << "\n\n";
                break;
            case 2:
                std::cout << "\n\n";
                goto newGame;
                break;
            case 3:
                std::cout << '\n';
                printDeck(cardDeck);
                std::cout << "\n\n";
                break;
            case 4:
                std::cout << "\n\tShuffling deck...\n";
                shuffleDeck(cardDeck);
                std::cout << "\n\n";
                break;
            case 5:
                std::cout << "\n\tThanks for playing Blackjack\n";
                return;
            default:
                std::cout << "Invalid option, choose again.\n\n";
                clearInput();
                break;
        }
    }
}
