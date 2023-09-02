#include "Game.h"
#include "Parser.h"
void Game::Initialize()
{
    Clear();
    interactor.Write("Welcome To Number Guessing Game");
    Play();
}
void Game::Play()
{
    numberToGuess = GetRandomNumber(1, 1000);
    interactor.Write("Guess a number between 1 and 1000: ");

    while (player.lastGuess != numberToGuess)
    {
        player.gusseCount++;
        Update();
    }
    interactor.Write("You guessed the number!");
    interactor.Write("You did it in " + std::to_string(player.gusseCount) + " guesses!");
    interactor.Write("Play again? Y/N: ");

    char input = Parser::ParseChar(interactor.Read());
    if (not(input == 'y' || input == 'Y'))
        isRunning = false;
}
void Game::Update()
{
    if (!player.lastGuess)
    {

        player.lastGuess = Parser::ParseInt(interactor.Read());
        return;
    }
    if (player.lastGuess < numberToGuess)
    {
        interactor.Write("Low! Guess again:");
    }
    else if (player.lastGuess > numberToGuess)
    {
        interactor.Write("High! Guess again:");
    }
    player.lastGuess = Parser::ParseInt(interactor.Read());
}
void Game::Clear()
{
    player.lastGuess = player.gusseCount = 0;
    system("clear");
}
void Game::Start()
{
    Initialize();
}
int GetRandomNumber(int min, int max)
{
    return std::rand() % (max - min + 1) + min;
}