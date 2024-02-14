#pragma once
#include "Pokemon.h"
#include <string>
#include <vector>
// Trainer.cpp
#include "Trainer.h"
#include <iostream>

Trainer::Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int maxPokemon, int numPokeballs)
    : firstName(firstName), lastName(lastName), catchphrase(catchphrase), money(money), lifePoints(lifePoints), maxPokemon(maxPokemon), numPokeballs(numPokeballs) {}

void Trainer::Introduce() const {
    std::cout << "Hi, I'm " << firstName << " " << lastName << ". " << catchphrase << "\n\n" << std::endl;
}

std::string Trainer::GetName() const {
    return firstName;
}

void Trainer::Challenge(Trainer& opponent) {
    std::cout << "Trainer " << firstName << " challenges Trainer " << opponent.firstName << " to a battle!" << std::endl;
}

void Trainer::CapturePokemon(Pokemon wildPokemon) {
    if (party.size() < maxPokemon) {
        party.push_back(wildPokemon);
        std::cout << "Trainer " << firstName << " captures a wild " << wildPokemon.GetName() << "!" << std::endl;
    }
    else {
        std::cout << "Trainer " << firstName << "'s party is full. Cannot capture " << wildPokemon.GetName() << "." << std::endl;
    }
}

void Trainer::SendOutPokemon(int index) {
    if (index >= 0 && index < party.size()) {
        party[index].GetOutBall();
        std::cout << "Trainer " << firstName << " sends out " << party[index].GetName() << "!" << std::endl;
    }
}

void Trainer::ChangePokemon(int index) {
    if (index >= 0 && index < party.size()) {
        party[index].GetInBall();
        std::cout << "Trainer " << firstName << " recalls " << party[index].GetName() << "." << std::endl;
    }
}

void Trainer::UsePokemonAbility(int abilityIndex, Pokemon& target) {

    if (!party.empty() && abilityIndex >= 0 && abilityIndex < party[0].GetAbilities().size()) {
        party[0].UseAbility(abilityIndex);

    }
}

void Trainer::EarnMoney(int amount) {
    money += amount;
    std::cout << "Trainer " << firstName << " earns " << amount << " money. Total money: " << money << std::endl;
}

void Trainer::EarnPokeballs(int amount) {
    numPokeballs += amount;
    std::cout << "Trainer " << firstName << " receives " << amount << " Pokeballs. Total Pokeballs: " << numPokeballs << std::endl;
}

int Trainer::GetPartySize() const {
    return static_cast<int>(party.size());
}