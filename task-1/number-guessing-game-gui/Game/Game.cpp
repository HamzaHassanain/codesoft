#include "Game.h"
#include <iostream>
Game::Game()
{
}
void Game::Init()
{
    numberToGuess = rand() % 9999 + 1;
    numberOfGuesses = 0;
    lastGuess = 0;

    std::cout << numberToGuess << std::endl;
}
int Game::GetNumberToGuess()
{
    return numberToGuess;
}
int Game::GetNumberOfGuesses()
{
    return numberOfGuesses;
}
void Game::SetLastGuess(int lastGuess)
{
    this->lastGuess = lastGuess;
}
int Game::GetLastGuess()
{
    return lastGuess;
}
void Game::Guess(int guess)
{
    numberOfGuesses++;
    lastGuess = guess;
}
short Game::GetGuessStatus()
{
    if (lastGuess == numberToGuess)
        return 0;
    else if (lastGuess < numberToGuess)
        return -1;
    else
        return 1;
}
void Game::Reset()
{
    Init();
}
Game::~Game()
{
}