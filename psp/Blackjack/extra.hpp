#ifndef EXTRA_H
#define EXTRA_H

// System commands
#if defined _WIN64 || _WIN32
constexpr char SYS_CLEAR[]{"cls"};
constexpr char SYS_SLEEP[]{"timeout /t 1 /nobreak > nul"}; // Windows doesn't supports float time
#else
constexpr char SYS_CLEAR[]{"clear"};
constexpr char SYS_SLEEP[]{"sleep 0.5"};
#endif

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
