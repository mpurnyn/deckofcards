cmake_minimum_required(VERSION 3.29)
project(deckofcards)

set(CMAKE_CXX_STANDARD 20)

add_executable(deckofcards main.cpp
        main.h
        dealer.h
        card.cpp
        card.h
        Deck.cpp
        Deck.h
        Player.cpp
        Player.h
        dealer.cpp)
