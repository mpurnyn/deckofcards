#ifndef CARD_H
#define CARD_H
#include <string>

// Enums for suit and rank
enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

// Helper functions to convert enum to string
std::string suitToString(Suit suit);
std::string rankToString(Rank rank);

class Card {
public:
    explicit Card(int i);
    void display();
    int value;
};

#endif //CARD_H
