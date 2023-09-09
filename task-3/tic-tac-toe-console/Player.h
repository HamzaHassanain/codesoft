#pragma once
#include "PlayerType.h"

struct Player
{
    bool Playable;
    PlayerType type;
    Player();
    Player(PlayerType, bool);

    bool operator==(const Player &other) const
    {
        return type == other.type;
    }
};
