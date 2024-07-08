# Problem Statement: Deck of Cards

This project implements a deck of cards, a dealer, a player class, and a card class.

The card class defines the cards as integers and maps them to a suit/

Program runs and spins off a thread for the dealer, and two players.

# Build
Compiled on Windows 11 with 242.16677.29. 
"{CMAKE_DIR}\cmake\win\x64\bin\cmake.exe" --build {PROJECTS_DIR}\deckofcards\cmake-build-debug --target deckofcards -j 14

# Usage
C:\Users\ppurn\CLionProjects\deckofcards\cmake-build-debug\deckofcards.exe

# Design Choices 
Cards
- The card class is a simple wrapper around an integer and keeps track of the mapping from integer to rank/suit.
- This was done for simplicity sake if cards to be used are not poker cards.

Dealer
- the dealer deals cards initially and to fill players hands between turns
- dealers prompts players to play their turns in order until the shuffle count reaches 3.
- the dealer keeps a reference of all the players to deal and prompt them during the game
- the dealer takes a max hand size and max reshuffle parameter to control game flow and end state
- there is no score tracking 

Players
- the players do not draw directly from the deck and do not discard directly 
to the deck but do it through the Dealer.
- This reduces the need to lock the deck
- the players had a play_turn() method discards one card from its hand per turn
- this function may be overriden to implement different turn logic

Deck
- the deck shuffles if its called to deal a card and the deck is empty
- the deck tracks its shuffle count
- the deck class maintains both deck cards and discard cards
- The shuffle implementation combines the two before swapping them in place according to a random number generator
