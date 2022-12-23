# Blackjack
## Simple Blackjack Game
---

## Rules
- Player and dealer will be given one card each.
- Player can either pull more cards or stand.
- If player cards score more than 21 player will loose.
- If player cards score is less than 21, dealer will pull cards until it's score reaches 17 or above.
- If dealers score is more than 21 he'll loose and player wins.
- If dealer scores more than player, dealer wins.

## Cards
- Cards 2-10 each values equal to their face value.
- Cards J, Q and K value 10.
- Card A is either 1 or 11 depending on the scores.

## Building
---
## Prerequisite
```make``` and ```gcc```

### Installation on Linux
Run the following command as root

```apt install make gcc```

### Installation on Windows
Run the following command to install using chocolatey

```choco install make mingw```

# Building
Open terminal/cmd and run

```make blackjack``` or ```make``` to build

```make clean``` to remove temporary build files.