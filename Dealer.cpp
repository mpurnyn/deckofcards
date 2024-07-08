#include "Dealer.h"
#include <iostream>
#include <vector>
#include <thread>

// Implementations of Dealer methods
Dealer::Dealer(std::vector<Player>& players, Deck& deck, int max_hand_size, int max_reshuffles) : players(players), deck(deck), max_hand_size(max_hand_size), max_reshuffles(max_reshuffles){
    std::cout << "Dealer: Initiated" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    deck.shuffle();
    deal_cards();
    for (Player& p : players) {
        int hand_size = p.get_hand_size();
        std::cout << p.name << " hand size: " << hand_size << std::endl;
    }
    prompt_turns();
}
void Dealer::deal_cards()  {
    std::cout << "Dealer: Dealing..." << std::endl;
    int turn = 0;
    for (int i = 0; i < max_hand_size * players.size(); ++i) {
        Card card = deck.deal_card();
        Player& p = players[turn];
        p.add_card(card);
        card.display();
        ++turn;
        turn = turn % players.size();
    }
}
void Dealer::discard_card(Card card) {
    deck.discard(card);
}
void Dealer::prompt_turns() {
    while(deck.shuffle_count < max_reshuffles) {
        for (Player& p : players) {
            p.play_turn(this, &Dealer::discard_card);
            if (p.get_hand_size() < max_hand_size) {
                Card card = deck.deal_card();
                if (deck.shuffle_count >= max_reshuffles) {
                    return;
                }
                p.add_card(card);
                card.display();
            }
        }
    }
}
void Dealer::operator()() const {
    std::cout << "Running thread for: Dealer" << std::endl;
}
