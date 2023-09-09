#include "Game.h"

Game::Game()
{
    player1.type = PlayerType::X;
    player2.type = PlayerType::O;
    currentPlayer = player1;
    currentCheckType = CheckType::None;
}
void Game::SetCell(int index)
{
    board.SetCell(index + 1, currentPlayer);
}
bool Game::win(std::string ch)
{
    if (board.GetBoard()[0] == ch && board.GetBoard()[1] == ch && board.GetBoard()[2] == ch)
    {
        winCellsIndex = {0, 1, 2};
        return true;
    }
    else if (board.GetBoard()[3] == ch && board.GetBoard()[4] == ch && board.GetBoard()[5] == ch)
    {
        winCellsIndex = {3, 4, 5};
        return true;
    }
    else if (board.GetBoard()[6] == ch && board.GetBoard()[7] == ch && board.GetBoard()[8] == ch)
    {
        winCellsIndex = {6, 7, 8};
        return true;
    }
    else if (board.GetBoard()[0] == ch && board.GetBoard()[3] == ch && board.GetBoard()[6] == ch)
    {
        winCellsIndex = {0, 3, 6};
        return true;
    }
    else if (board.GetBoard()[1] == ch && board.GetBoard()[4] == ch && board.GetBoard()[7] == ch)
    {
        winCellsIndex = {1, 4, 7};
        return true;
    }
    else if (board.GetBoard()[2] == ch && board.GetBoard()[5] == ch && board.GetBoard()[8] == ch)
    {
        winCellsIndex = {2, 5, 8};
        return true;
    }
    else if (board.GetBoard()[0] == ch && board.GetBoard()[4] == ch && board.GetBoard()[8] == ch)
    {
        winCellsIndex = {0, 4, 8};
        return true;
    }
    else if (board.GetBoard()[2] == ch && board.GetBoard()[4] == ch && board.GetBoard()[6] == ch)
    {
        winCellsIndex = {2, 4, 6};
        return true;
    }
    else
        return false;
}
void Game::CheckGameMode()
{

    if (win("X"))
    {
        currentCheckType = CheckType::X;
    }
    else if (win("O"))
    {
        currentCheckType = CheckType::O;
    }
    else if (board.Full())
    {
        currentCheckType = CheckType::Draw;
    }
    else
        currentCheckType = CheckType::None;
}
