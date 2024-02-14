#pragma once

#include "Trainer.h"
#include "Pokemon.h"
#include "Battle.h"
#include "Ability.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PokemonFight.h"


using namespace std;


int main() {
    std::srand(std::time(0));



    Trainer ash("Ash", "Ketchum", "I choose you!", 1000, 100, 6, 10);
    Trainer misty("Misty", "Waterflower", "Let's go, Starmie!", 900, 90, 6, 8);
    Trainer brock("Brock", "Rock-Solid", "Geodude, let's rock!", 800, 80, 6, 6);


    pikachu.LearnAbility(thunderShock);


    starmie.LearnAbility(waterGun);


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
        Pokemon* third = nullptr;

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

        std::cout << "\nChoose your second Pokemon (1. Pikachu, 2. Starmie, 3. Geodude) : ";
        int pokemonChoice2;
        std::cin >> pokemonChoice2;

        Pokemon* otherPokemon = nullptr;

        switch (pokemonChoice2) {
        case 1:
            otherPokemon = &pikachu;
            break;
        case 2:
            otherPokemon = &starmie;
            break;
        case 3:
            otherPokemon = &geodude;
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


            while ((currentPokemon->GetLife() > 0 || otherPokemon->GetLife() > 0) && wildPokemon.GetLife() > 0) {

                std::cout << "\n\n1- Use an ability   2- Switch Pokemons" << std::endl;


                int actionChoice;
                std::cin >> actionChoice;

                if (actionChoice == 1) {

                    std::cout << currentPokemon->GetName() << " abilities : " << std::endl;

                    const std::vector<Ability>& abilities = currentPokemon->GetAbilities();
                    for (const auto& ability : abilities) {
                        std::cout << ability.GetName() << "\n";

                        if (ability.GetRemainingUses() > 0) {


                            int damage = ability.GetDamage();
                            wildPokemon.TakeDamage(damage);
                            std::cout << wildPokemon.GetName() << " has now " << wildPokemon.GetLife() << " HP ";
                            std::cout << "\nYour " << currentPokemon->GetName() << " has now " << currentPokemon->GetLife() << " HP ";

                            ability.DecreaseMaxUses();
                            std::cout << "\nReamining uses : " << ability.remainingUses << "";

                        }

                        else {

                            std::cout << "\nYou can't use this ability anymore, your Pokemon needs to rest !! \nTherefore you loose your turn...Try to let your Pokemons rest next time :/";

                        }

                    }


                    std::cout << std::endl;


                }


                else if (actionChoice == 2){

                    third = currentPokemon;
                    currentPokemon = otherPokemon;
                    otherPokemon = third;
                    std::cout << "\nYour current Pokemon is now " << currentPokemon->GetName() << " (remaining life " << currentPokemon->GetLife() << ") ";


                }



                if (wildPokemon.GetLife() > 0) {

                    const std::vector<Ability>& abilities = wildPokemon.GetAbilities();
                    for (const auto& ability : abilities) {
                        //std::cout << ability.GetName() << "\n";
                        int damage = ability.GetDamage();
                        currentPokemon->TakeDamage(damage);
                        std::cout << "\n" << wildPokemon.GetName() << " is attacking you with " << ability.GetName() << " !";
                    }

                    std::cout << "\nYour " << currentPokemon->GetName() << " has now " << currentPokemon->GetLife() << " HP ";

                    if (currentPokemon->GetLife() == 0 && otherPokemon->GetLife() > 0) {

                        third = currentPokemon;
                        currentPokemon = otherPokemon;
                        otherPokemon = third;
                        std::cout << "\nYour current Pokemon is now " << currentPokemon->GetName() << " (remaining life " << currentPokemon->GetLife() << ") ";
                    }

                }


            }


            if (wildPokemon.GetLife() == 0) {

                std::cout << "Congratulations! You captured the wild " << wildPokemon.GetName() << "!" << std::endl;

            }

            if (currentPokemon->GetLife() == 0 && otherPokemon->GetLife() == 0 && third->GetLife() == 0) {

                std::cout << "\nYou were defeated by " << wildPokemon.GetName() << "... That sucks :/ " << std::endl;

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
        std::cout << "Do you want to play again? :)  (1. Yes, 2. No) ";
        int playAgainChoice;
        std::cin >> playAgainChoice;

        if (playAgainChoice != 1) {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        }
    }

    return 0;
}
