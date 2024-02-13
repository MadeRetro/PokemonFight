#pragma once
#include "Battle.h"
#include "Pokemon.h"
#include <iostream>

using namespace std;

Battle::Battle(Trainer& player, Pokemon& opponent) {
    // ... (constructor implementation)
}

void Battle::Start() {
    std::cout << "The batlle starts ! ";
    // I would like to access the current Pokemon the player is using here and display its abilities
}

bool Battle::GetPlayerWins() const {
    // ... (implementation to check if the player wins)
    return false;  // Placeholder return value
}
