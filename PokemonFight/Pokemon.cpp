// Pokemon.cpp
#include "Pokemon.h"

Pokemon::Pokemon(std::string name, std::string description, PokeType type, int level, int life)
    : name(name), description(description), type(type), level(level), life(life) {}

void Pokemon::LearnAbility(Ability ability) {
    abilities.push_back(ability);
}

void Pokemon::UseAbility(int abilityIndex) {
    if (abilityIndex >= 0 && abilityIndex < abilities.size()) {
        abilities[abilityIndex].Use();
    }
}

void Pokemon::Rest() {
    for (auto& ability : abilities) {
        ability.ResetUses();
    }
}

void Pokemon::GetInBall() {
    inBall = true;
}

void Pokemon::GetOutBall() {
    inBall = false;
}

std::string Pokemon::GetName() const {
    return name;
}

std::string Pokemon::GetDescription() const {
    return description;
}

PokeType Pokemon::GetType() const {
    return type;
}

int Pokemon::GetLevel() const {
    return level;
}

int Pokemon::GetLife() const {
    return life;
}

const std::vector<Ability>& Pokemon::GetAbilities() const {
    return abilities;
}
