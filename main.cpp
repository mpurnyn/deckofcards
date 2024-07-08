#include "main.h"
#include "Player.h"
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include "Deck.h"
#include "Dealer.h"
#include <sstream>
#include <fstream>

// main function
int main() {
    int max_hand_size = 5;
    int max_reshuffles = 3;

    std::vector<std::thread> threads;
    std::vector<Player> players;
    Deck deck;

    std::vector<std::string> names = {"Player1", "Player2"};
    for (const auto& name : names) {
        players.emplace_back(Player(name));
    }

    Dealer dealer(players, deck, max_hand_size, max_reshuffles);
    threads.emplace_back(std::ref(dealer));

    for (Player& player : players) {
        threads.emplace_back(std::ref(player));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "All threads completed." << std::endl;
    return 0;
}
