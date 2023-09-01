#pragma once
#include "Player.h"
#include "Interactor.h"
class Game
{

private:
    Interactor interactor;
    Player player;
    int numberToGuess;

    void Initialize();
    void Play();
    void Update();
    void Clear();

public:
    bool isRunning = true;
    void Start();
};
int GetRandomNumber(int, int);