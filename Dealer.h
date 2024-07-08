#ifndef DEALER_H
#define DEALER_H
#include <vector>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class Dealer {
public:
    explicit Dealer(std::vector<Player>& players, Deck& deck, int max_hand_size, int max_reshuffles);
    void deal_cards();
    void discard_card(Card card);
    void prompt_turns();
    void operator()() const;
    int max_hand_size;
    int max_reshuffles;
private:
    std::vector<Player>& players;
    Deck& deck;
};

#endif //DEALER_H
