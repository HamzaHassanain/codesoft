#include "Player.h"
Player::Player()
{
    Playable = false;
    type = PlayerType::X;
}

Player::Player(PlayerType type, bool playable = true)
{
    this->type = type;
    this->Playable = playable;
}
