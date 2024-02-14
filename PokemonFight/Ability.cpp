
#pragma once
#include <string>
#include "Ability.h"
#include <iostream>
using namespace std;

Ability::Ability(std::string name, int damage, PokeType type, int maxUses)
    : name(name), damage(damage), type(type), remainingUses(maxUses), maxUses(maxUses) {}

std::string Ability::GetName() const {
    return name;
}

int Ability::GetDamage() const {
    return damage;
}

PokeType Ability::GetType() const {
    return type;
}

int Ability::GetRemainingUses() const {
    return remainingUses;

}

void Ability::Use() {
    if (remainingUses > 0) {
        // Perform ability action
        remainingUses--;
    }
    else {
        std::cout << "You can't use this ability, your pokemon needs to rest !! ";
    }
}

void Ability::DecreaseMaxUses() const{
    if (maxUses > 0) {
        maxUses--;
    }
    if (remainingUses > 0) {
        remainingUses--;
    }
}

void Ability::ResetUses() {
    remainingUses = 0; // Reset to max uses
}

Ability thunderShock("Thunder Shock", 15, PokeType::Electric, 4);
Ability waterGun("Water Gun", 12, PokeType::Water, 4);
Ability rockThrow("Rock Throw", 10, PokeType::Rock, 4);