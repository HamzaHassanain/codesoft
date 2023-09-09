#pragma once
#include "Board.h"
#include "Player.h"
#include "CheckType.h"
#include "GameMode.h"
class Game
{
private:
    bool win(std::string ch);

public:
    Player player1;
    Player player2;
    CheckType currentCheckType;
    Player currentPlayer;
    GameMode gameMode = GameMode::PlayerVsPlayer;
    Board board;
    std::vector<int> winCellsIndex;
    Game();
    void SetCell(int);
    void CheckGameMode();
};