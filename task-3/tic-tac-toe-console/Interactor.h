#pragma once
#include "Board.h"
#include "GameMode.h"
class Interactor
{

public:
    int GetCell();
    GameMode GetGameMode();
    void ShowPlayers();
    void ShowBoard(Board &);
    void ShowTurn(Player);
    void ShowWinner(Player);
    void ShowDraw();
};
