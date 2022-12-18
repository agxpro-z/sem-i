#
# Blackjack
#

# Variables
CC = g++
CC_VERSION = -std=c++2a
CC_FLAGS = -pedantic-errors

# Make Blackjack game
binary: main.o card.o deck.o extra.o game.o
	@echo
	@echo Linking...
	@g++ $(CC_VERSION) $(CC_FLAGS) -o $@ $?
	@echo "$? -> binary"

main.o: main.cpp
	@echo building...
	@echo
	@echo "main.cpp -> main.o"
	@g++ $(CC_VERSION) $(CC_FLAGS) -c $?

card.o: card.cpp
	@echo "card.cpp -> card.o"
	@g++ $(CC_VERSION) $(CC_FLAGS) -c $?

deck.o: deck.cpp
	@echo "deck.cpp -> deck.o"
	@g++ $(CC_VERSION) $(CC_FLAGS) -c $?

extra.o: extra.cpp
	@echo "extra.cpp -> extra.o"
	@g++ $(CC_VERSION) $(CC_FLAGS) -c $?

game.o: game.cpp
	@echo "game.cpp -> game.o"
	@g++ $(CC_VERSION) $(CC_FLAGS) -c $?

# Clean build dir
clean:
	@echo Cleaing...
	@rm -f binary *.o
