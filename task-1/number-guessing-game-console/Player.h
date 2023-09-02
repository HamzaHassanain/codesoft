#pragma once

struct Player
{
    int lastGuess;
    int gusseCount = 0;

    Player(int guess) : lastGuess(guess) {}
    Player() {}
};