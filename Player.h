#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"
#include <chrono>
#include <string>
#include "Card.h"

class Dealer;

class Player {
public:
    explicit Player(const std::string &name);
    void operator()() const;
    int get_hand_size();
    void play_turn(Dealer* dealer, void (Dealer::*callback)(Card));
    void add_card(Card card);
    std::string name;
private:
    std::vector<Card> hand;
    void show_hand();
};

#endif //PLAYER_H
