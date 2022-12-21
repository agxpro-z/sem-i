#ifndef EXTRA_H
#define EXTRA_H

// System commands
constexpr char SYS_CLEAR[]{"clear"};
constexpr char SYS_SLEEP[]{"sleep 0.5"};

/*
 * Clear cin buffer
 */
void clearInput();

// Pause game until enter is pressed
void getKey();

/*
 * Print Game Menu
 */
void menu();

// Shuffling text animation
void shufflingAnimation();

#endif
