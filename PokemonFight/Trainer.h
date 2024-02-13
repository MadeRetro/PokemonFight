// Trainer.h
#pragma once
#include "Pokemon.h"
#include <string>
#include <vector>

class Trainer {
public:
    Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int maxPokemon, int numPokeballs);

    void Introduce() const;
    void Challenge(Trainer& opponent);
    void CapturePokemon(Pokemon wildPokemon);
    void SendOutPokemon(int index);
    void ChangePokemon(int index);
    void UsePokemonAbility(int abilityIndex, Pokemon& target);
    void EarnMoney(int amount);
    void EarnPokeballs(int amount);
    int GetPartySize() const;

private:
    std::string firstName;
    std::string lastName;
    std::string catchphrase;
    int money;
    int lifePoints;
    int maxPokemon;
    int numPokeballs;
    std::vector<Pokemon> party;
};