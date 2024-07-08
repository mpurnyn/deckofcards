#include "Deck.h"
#include "Card.h"
#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>

Deck::Deck() : shuffle_count(0) {
    for (int s = 0; s < 4; ++s) {
        for (int r = 0; r < 13; ++r) {
            cards.emplace_back(Card(s * 13 + r));
        }
    }
}
/**
 * Shuffles the elements of a vector randomly.
 * this function shuffles the deck by inserting the discard pile into the deck and then shuffling the deck
 * the algorithm implements a Fisher-Yates shuffle which is a modern algorithm for shuffling an array that does not require any extra memory and runs in O(n) time complexity
 */
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Add discard pile to deck prior to shuffling
    if (cards.empty()) {
        cards = discard_pile;
    } else {
        cards.insert(cards.end(), discard_pile.begin(), discard_pile.end());
    }
    discard_pile.clear();

    // shuffling algorithm
    for (int i = cards.size() - 1; i >= 1; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(cards[j], cards[i]);
    }
    shuffle_count++;
    std::cout << "Suffled " << shuffle_count << " times" << std::endl;
}

Card Deck::get_top_card() {
    if (cards.empty()) {
        std::cout << "Deck is empty" << std::endl;
        return Card(-1);
    }
    return cards.back();
}
Card Deck::deal_card() {
    if (cards.empty()) {
        shuffle();
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}
void Deck::discard(Card card) {
    discard_pile.push_back(card);
}
