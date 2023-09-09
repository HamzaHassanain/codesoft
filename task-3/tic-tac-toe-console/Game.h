#pragma once
#include "Clear.h"
#include "Board.h"
#include "Interactor.h"
#include "Player.h"
#include "CheckType.h"
class Game
{
    Player player1;
    Player player2;
    Player currentPlayer;
    CheckType currentCheckType;

    Board board;
    Interactor interactor;

    void CheckBoard();

public:
    Game();
    void Init();
    void Start();
    void Play();
    void End();
};