#pragma once
#include "Battle.h"
#include "Pokemon.h"
#include <iostream>

using namespace std;

extern Pokemon pikachu;
extern Ability thunderShock;
extern Pokemon currentPokemon;


Battle::Battle(Trainer& player, Pokemon& opponent) {
    // ... (constructor implementation)
}

void Battle::Start() {
    std::cout << "\nThe battle starts ! ";

    //Assuming currentPokemon is set somewhere
    //const std::vector<Ability>& abilities = currentPokemon.GetAbilities();
    //for (const auto& ability : abilities) {
    //    std::cout << ability.GetName() << " ";
    //}
    //std::cout << std::endl;
}


bool Battle::GetPlayerWins() const {
    // ... (implementation to check if the player wins)
    return false;  // Placeholder return value
}
