#include "Board.h"

Board::Board()
{
    Init();
}
void Board::Init()
{
    board = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
}
void Board::SetCell(int cell, Player player)
{
    cell--;
    if (cell < 0 || cell > 8)
        return;
    if (board[cell] == "X" || board[cell] == "O")
        return;

    board[cell] = player.type == PlayerType::X ? "X" : "O";
}
std::vector<std::string> Board::GetBoard()
{
    return board;
}

int Board::GetRandomCell()
{
    int cell;
    std::vector<int> empty;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != "X" && board[i] != "O")
            empty.push_back(i);
    }
    cell = rand() % empty.size();
    return empty[cell];
}
bool Board::Full()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != "X" && board[i] != "O")
            return false;
    }
    return true;
}