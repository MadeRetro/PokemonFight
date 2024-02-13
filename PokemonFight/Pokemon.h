// Pokemon.h
#pragma once
#include "Ability.h"
#include <string>
#include <vector>
#include "PokeType.h"
using namespace std;

class Pokemon {
public:
    Pokemon(std::string name, std::string description, PokeType type, int level, int life);

    void LearnAbility(Ability ability);
    void UseAbility(int abilityIndex);
    void Rest();
    void GetInBall();
    void GetOutBall();

    std::string GetName() const;
    std::string GetDescription() const;
    PokeType GetType() const;
    int GetLevel() const;
    int GetLife() const;
    const std::vector<Ability>& GetAbilities() const; // Added method

private:
    std::string name;
    std::string description;
    PokeType type;
    int level;
    int life;
    std::vector<Ability> abilities;
    bool inBall;
};


