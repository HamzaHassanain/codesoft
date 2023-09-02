#pragma once

class Game
{
public:
    Game();
    ~Game();

    void Init();

    int GetNumberToGuess();
    int GetNumberOfGuesses();

    void SetLastGuess(int lastGuess);
    int GetLastGuess();

    void Guess(int guess);
    void Reset();

    short GetGuessStatus();

private:
    int numberToGuess;
    int numberOfGuesses;
    int lastGuess;
};