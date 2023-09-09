#pragma once
#include "Player.h"
#include <string>
#include <vector>
class Board
{
    std::vector<std::string> board;

public:
    Board();
    void Init();
    void SetCell(int, Player);
    int GetRandomCell();
    bool Full();
    std::vector<std::string> GetBoard();
};