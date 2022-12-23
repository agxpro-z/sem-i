#
# Blackjack
#

# Compiler variables
CC = g++
CC_VERSION = -std=c++2a
CC_FLAGS = -pedantic-errors

# OS specific variables
ifeq ($(OS), Windows_NT)
	BIN = Blackjack.exe
	CLEAN = del /q *.o
else
	BIN = Blackjack
	CLEAN = rm -f *.o
endif

# Make Blackjack game
blackjack: main.o card.o deck.o extra.o game.o player.o
	@echo
	@echo Linking...
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -o $(BIN) $?
	@echo "$? -> $(BIN)"

main.o: main.cpp
	@echo Building...
	@echo "main.cpp -> main.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

card.o: card.cpp
	@echo "card.cpp -> card.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

deck.o: deck.cpp
	@echo "deck.cpp -> deck.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

extra.o: extra.cpp
	@echo "extra.cpp -> extra.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

game.o: game.cpp
	@echo "game.cpp -> game.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

player.o: player.cpp
	@echo "player.cpp -> player.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

# Clean build dir
clean:
	@echo Cleaing...
	@$(CLEAN) $(BIN)
