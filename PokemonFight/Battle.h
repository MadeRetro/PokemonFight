// Battle.h
#pragma once
#include "Trainer.h"
#include "Pokemon.h"

class Battle {
public:
    Battle(Trainer& player, Pokemon& opponent);
    void Start();  // Declaration for the Start function
    bool GetPlayerWins() const;  // Declaration for the GetPlayerWins function

private:
    // ... (other member variables and functions)
};
