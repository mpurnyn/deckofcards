//
// Created by ppurn on 7/8/2024.
//

#include "Card.h"
#include <iostream>


// Implementations of helper functions
std::string suitToString(Suit suit) {
    switch (suit) {
        case Suit::Hearts: return "Hearts";
        case Suit::Diamonds: return "Diamonds";
        case Suit::Clubs: return "Clubs";
        case Suit::Spades: return "Spades";
        default: return "Unknown";
    }
}
std::string rankToString(Rank rank) {
    switch (rank) {
        case Rank::Two: return "Two";
        case Rank::Three: return "Three";
        case Rank::Four: return "Four";
        case Rank::Five: return "Five";
        case Rank::Six: return "Six";
        case Rank::Seven: return "Seven";
        case Rank::Eight: return "Eight";
        case Rank::Nine: return "Nine";
        case Rank::Ten: return "Ten";
        case Rank::Jack: return "Jack";
        case Rank::Queen: return "Queen";
        case Rank::King: return "King";
        case Rank::Ace: return "Ace";
        default: return "Unknown";
    }
}

// Implementations of Card methods
Card::Card(int i) : value(i) {}
void Card::display()  {
    int s = value / 13;
    int r = value % 13;
    Suit suit = static_cast<Suit>(s);
    Rank rank = static_cast<Rank>(r);
    std::cout << "Card: " << rankToString(rank) << " of " << suitToString(suit) << std::endl;
}
