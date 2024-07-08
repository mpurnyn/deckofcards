#include "Player.h"
#include <chrono>
#include <string>
#include <iostream>
#include "Card.h"

// Implementations of Player methods
Player::Player(const std::string &name) : name(name) {
    std::cout << name << ": Initiated" << std::endl;
}
void Player::operator()() const {
    std::cout << "Running thread for: " << name << std::endl;
}
int Player::get_hand_size() {
    return hand.size();
}
void Player::play_turn(Dealer* dealer, void (Dealer::*callback)(Card)) {
    std::cout << name << ": playing turn" << std::endl;
    if (!hand.empty()) {
        Card card = hand.back();
        hand.pop_back();
        // Assume dealer instance is available
        (dealer->*callback)(card);
    }
}
void Player::add_card(Card card) {
    hand.push_back(card);
}
void Player::show_hand()  {
    std::cout << name << ": Hand: ";
    for (Card& card : hand) {
        card.display();
    }
    std::cout << std::endl;
}
