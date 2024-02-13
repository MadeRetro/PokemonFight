// PokemonFight.cpp : This file contains the 'main' function. Program execution begins and ends there.

#pragma once

#include "Trainer.h"
#include "Pokemon.h"
#include "Battle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    std::srand(std::time(0));



    Trainer ash("Ash", "Ketchum", "I choose you!", 1000, 100, 6, 10);
    Trainer misty("Misty", "Waterflower", "Let's go, Starmie!", 900, 90, 6, 8);
    Trainer brock("Brock", "Rock-Solid", "Geodude, let's rock!", 800, 80, 6, 6);

    Pokemon pikachu("Pikachu", "Electric mouse", PokeType::Electric, 10, 50);
    Ability thunderShock("Thunder Shock", 15, PokeType::Electric, 5);
    pikachu.LearnAbility(thunderShock);

    Pokemon starmie("Starmie", "Water-psychic star", PokeType::Water, 12, 60);
    Ability waterGun("Water Gun", 12, PokeType::Water, 5);
    starmie.LearnAbility(waterGun);

    Pokemon geodude("Geodude", "Rock-ground rock", PokeType::Rock, 8, 40);
    Ability rockThrow("Rock Throw", 10, PokeType::Rock, 5);
    geodude.LearnAbility(rockThrow);


    // Main loop
    while (true) {
        std::cout << "Choose a trainer to play (1. Ash, 2. Misty, 3. Brock): ";
        int trainerChoice;
        std::cin >> trainerChoice;

        Trainer* currentTrainer = nullptr;

        switch (trainerChoice) {
        case 1:
            currentTrainer = &ash;
            break;
        case 2:
            currentTrainer = &misty;
            break;
        case 3:
            currentTrainer = &brock;
            break;
        default:
            std::cout << "Invalid choice. Exiting." << std::endl;
            return 1;
        }

        // Choose Pokemon
        std::cout << "Choose your Pokemon (1. Pikachu, 2. Starmie, 3. Geodude) : ";
        int pokemonChoice;
        std::cin >> pokemonChoice;

        Pokemon* currentPokemon = nullptr;

        switch (pokemonChoice) {
        case 1:
            currentPokemon = &pikachu;
            break;
        case 2:
            currentPokemon = &starmie;
            break;
        case 3:
            currentPokemon = &geodude;
            break;
        default:
            std::cout << "Invalid choice. Exiting." << std::endl;
            return 1;
        }

        currentTrainer->SendOutPokemon(pokemonChoice - 1);

        // Choose action (1. Capture Pokemon, 2. Fight Trainer)
        std::cout << "Choose your action (1. Capture Pokemon, 2. Fight Trainer): ";
        int actionChoice;
        std::cin >> actionChoice;

        if (actionChoice == 1) {
            // Simulate a wild Pokemon encounter
            int wildPokemonIndex = std::rand() % 3; // Assuming 3 wild Pokemon available
            Pokemon wildPokemon = (wildPokemonIndex == 0) ? pikachu : ((wildPokemonIndex == 1) ? starmie : geodude);

            std::cout << "A wild " << wildPokemon.GetName() << " appears!" << std::endl;

            // Start the battle
            Battle wildBattle(*currentTrainer, wildPokemon);
            wildBattle.Start();

            // Check if the wild Pokemon was captured
            if (wildBattle.GetPlayerWins()) {
                std::cout << "Congratulations! You captured the wild " << wildPokemon.GetName() << "!" << std::endl;
            }
        }
        else if (actionChoice == 2) {
            // Implement logic for fighting another trainer
            // ...
        }
        else {
            std::cout << "Invalid choice. Exiting." << std::endl;
            return 1;
        }

        // Ask if the user wants to play again
        std::cout << "Do you want to play again? (1. Yes, 2. No): ";
        int playAgainChoice;
        std::cin >> playAgainChoice;

        if (playAgainChoice != 1) {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        }
    }

    return 0;
}
