#include "Interactor.h"
#include "Clear.h"
#include <iostream>

int Interactor::GetCell()
{

    std::cout << "Enter cell number: ";

    int cell;
    std::cin >> cell;
    if (cell < 1 || cell > 9)
        throw std::invalid_argument("Invalid game cell");

    return cell;
}

GameMode Interactor::GetGameMode()
{

    std::cout << "Tic Tac Toe\n";
    std::cout << "1. Player vs Player\n";
    std::cout << "2. Player vs Computer\n";
    std::cout << "0. Exit\n";

    std::cout << "Enter game mode: ";
    int mode;
    std::cin >> mode;

    if (mode < 0 || mode > 2)
        throw std::invalid_argument("Invalid game mode");

    return static_cast<GameMode>(mode);
}

void Interactor::ShowWinner(Player player)
{
    std::string ch = (player.type == PlayerType::X ? "X" : "O");
    std::cout << std::endl;
    std::cout << "Congrats: " << ch << "\n";
    std::cout << "Winner: " << ch << "\n";
}

void Interactor::ShowDraw()
{
    std::cout << std::endl;
    std::cout << "OPS!!!!!\n";
    std::cout << "Draw\n";
}
void Interactor::ShowTurn(Player player)
{
    std::string ch = (player.type == PlayerType::X ? "X" : "O");
    std::cout << "Turn: " << ch << "\n";
}
void Interactor::ShowBoard(Board &board)
{
    std::cout << "\n";
    auto cells = board.GetBoard();
    for (int i = 0; i < 9; i++)
    {
        std::cout << cells[i];
        if ((i + 1) % 3 == 0)
        {
            std::cout << "\n";
            if (i != 8)
                std::cout << "---------\n";
        }
        else
            std::cout << " | ";
    }
    std::cout << "\n";
}

void Interactor::ShowPlayers()
{
    std::cout << "Player 1: X\n";
    std::cout << "Player 2: O\n";
}