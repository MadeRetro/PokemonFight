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

    // New function to decrease maxUses
    void DecreaseMaxUses() const;

    mutable int remainingUses;

private:
    std::string name;
    int damage;
    PokeType type;
    mutable int maxUses;

};

extern Ability thunderShock;
extern Ability waterGun;
extern Ability rockThrow;