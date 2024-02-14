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

void Pokemon::TakeDamage(int damage) {
    life -= damage;
    if (life < 0) {
        life = 0;  // Ensure life doesn't go below zero
    }
}

Pokemon pikachu("Pikachu", "Electric mouse", PokeType::Electric, 10, 50);


Pokemon starmie("Starmie", "Water-psychic star", PokeType::Water, 12, 60);


Pokemon geodude("Geodude", "Rock-ground rock", PokeType::Rock, 8, 40);
