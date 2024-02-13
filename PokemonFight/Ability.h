// Ability.h
#pragma once
#include <string>
#include "PokeType.h"

class Ability {
public:
    Ability(std::string name, int damage, PokeType type, int maxUses);

    std::string GetName() const;
    int GetDamage() const;
    PokeType GetType() const;
    int GetRemainingUses() const;

    void Use();
    void ResetUses();

private:
    std::string name;
    int damage;
    PokeType type;
    int remainingUses;
};