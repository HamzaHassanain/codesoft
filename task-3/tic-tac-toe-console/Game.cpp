#include "Game.h"
#include <iostream>
#include <thread>
#include <cstdlib>
#include <unistd.h>
Game::Game()
{
    Clear();
    Init();
}

void Game::Init()
{
    GameMode gameMode = interactor.GetGameMode();
    if (gameMode == GameMode::Exit)
        exit(0);
    player1 = Player(PlayerType::X, true);

    if (gameMode == GameMode::PlayerVsPlayer)
        player2 = Player(PlayerType::O, true);

    else if (gameMode == GameMode::PlayerVsComputer)
        player2 = Player(PlayerType::O, false);

    currentPlayer = player1;

    board.Init();

    Play();
}

void Game::Play()
{
    while (true)
    {
        Clear();

        interactor.ShowPlayers();
        interactor.ShowBoard(board);
        interactor.ShowTurn(currentPlayer);

        if (currentPlayer.Playable == false)
        {
            int cell = board.GetRandomCell();
            sleep(3);
            board.SetCell(cell, currentPlayer);
        }
        else
        {

            int cell = interactor.GetCell();
            board.SetCell(cell, currentPlayer);
        }

        CheckBoard();

        if (currentCheckType == CheckType::X or currentCheckType == CheckType::O)
        {
            interactor.ShowWinner(currentPlayer);
            break;
        }
        else if (currentCheckType == CheckType::Draw)
        {
            interactor.ShowDraw();
            break;
        }
        else
        {
            currentPlayer = currentPlayer.type == PlayerType::X ? player2 : player1;
        }
    }
    End();
}

void Game::End()
{
    std::cout << std::endl;

    std::cout << "Game Over\n";
    std::cout << "Press any key to continue...";
    std::cin.get();
    std::cin.get();

    Clear();
    Init();
}

bool win(std::vector<std::string> &board, std::string ch)
{
    return ((board[0] == ch && board[1] == ch && board[2] == ch) ||
            (board[3] == ch && board[4] == ch && board[5] == ch) ||
            (board[6] == ch && board[7] == ch && board[8] == ch) ||
            (board[0] == ch && board[3] == ch && board[6] == ch) ||
            (board[1] == ch && board[4] == ch && board[7] == ch) ||
            (board[2] == ch && board[5] == ch && board[8] == ch) ||
            (board[0] == ch && board[4] == ch && board[8] == ch) ||
            (board[2] == ch && board[4] == ch && board[6] == ch));
}

void Game::CheckBoard()
{
    auto currentBoard = board.GetBoard();
    if (win(currentBoard, "X"))
    {
        currentCheckType = CheckType::X;
    }
    else if (win(currentBoard, "O"))
    {
        currentCheckType = CheckType::O;
    }
    else if (board.Full())
    {
        currentCheckType = CheckType::Draw;
    }
    else
    {
        currentCheckType = CheckType::None;
    }
}
