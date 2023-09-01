#include "Game.h"
#include "Parser.h"
#include "UISpecific.h"
void Game::Initialize()
{
    Clear();
    interactor.Write(UISpecific::GetUI_WELCOME());
    Play();
}
void Game::Play()
{
    numberToGuess = GetRandomNumber(1, 1000);
    interactor.Write(UISpecific::GetUI_GUESS_MESSAGE());

    while (player.lastGuess != numberToGuess)
    {
        player.gusseCount++;
        Update();
    }
    interactor.Write(UISpecific::GetUI_CORRECT_GUESS());
    interactor.Write(UISpecific::GetUI_GUESS_COUNT(player.gusseCount));
    interactor.Write(UISpecific::GetUI_PLAY_AGAIN());

    char input = Parser::ParseChar(interactor.Read());
    if (not UISpecific::IsUIPossitve(input))
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
        interactor.Write(UISpecific::GetUI_GUESS_AGAIN_LOWER());
    }
    else if (player.lastGuess > numberToGuess)
    {
        interactor.Write(UISpecific::GetUI_GUESS_AGAIN_HIGHER());
    }
    player.lastGuess = Parser::ParseInt(interactor.Read());
}
void Game::Clear()
{
    player.lastGuess = player.gusseCount = 0;
    UISpecific::ClearScreen();
}
void Game::Start()
{
    Initialize();
}
int GetRandomNumber(int min, int max)
{
    return std::rand() % (max - min + 1) + min;
}