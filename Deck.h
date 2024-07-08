#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
public:
    Deck();
    void shuffle();
    Card get_top_card();
    Card deal_card();
    void discard(Card card);
    int shuffle_count;
private:
    std::vector<Card> cards;
    std::vector<Card> discard_pile;
};

#endif //DECK_H
