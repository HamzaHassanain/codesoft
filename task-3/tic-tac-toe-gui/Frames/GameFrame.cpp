#include "GameFrame.h"
#include <iostream>

GameFrame::GameFrame(Game *game) : wxFrame(nullptr, wxID_ANY, "Tic Tac Toe")
{
    this->game = game;

    std::cout << "GameFrame constructor" << std::endl;
    InitializeComponents();
    SetSizers();
    BindEvents();
}
void GameFrame::InitializeComponents()
{
    std::string gameMode = game->gameMode == GameMode::PlayerVsPlayer ? "Player Vs Player" : "Player Vs Computer";
    std::string player = game->currentPlayer.type == PlayerType::X ? "X" : "O";
    font = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    panel = new wxPanel(this);
    cellsPanel = new wxPanel(panel);

    gameModeText = new wxStaticText(panel, wxID_ANY, gameMode, wxDefaultPosition, wxSize(400, 50), wxALIGN_CENTER);
    playerText = new wxStaticText(panel, wxID_ANY, "Player " + player + " Turn", wxDefaultPosition, wxSize(400, 50), wxALIGN_CENTER);

    gameModeText->SetFont(font);
    playerText->SetFont(font);

    for (int i = 0; i < 9; i++)
    {
        wxButton *cell = new wxButton(cellsPanel, wxID_ANY, "");
        cell->SetFont(font);
        cells.push_back(cell);
    }
}
void GameFrame::SetSizers()
{
    sizer = new wxBoxSizer(wxVERTICAL);
    panelSizer = new wxBoxSizer(wxVERTICAL);
    cellsPanelSizer = new wxGridSizer(3, 3, 0, 0);

    sizer->Add(panel, 1, wxEXPAND);
    panelSizer->Add(gameModeText, 1, wxEXPAND | wxTOP, 10);
    panelSizer->Add(playerText, 1, wxEXPAND | wxBOTTOM, 10);
    panelSizer->Add(cellsPanel, 3, wxALIGN_CENTER | wxBOTTOM, 100);

    for (int i = 0; i < 9; i++)
    {
        cellsPanelSizer->Add(cells[i], 1, wxEXPAND);
    }

    panel->SetSizerAndFit(panelSizer);
    cellsPanel->SetSizerAndFit(cellsPanelSizer);
    this->SetSizerAndFit(sizer);
}
void GameFrame::BindEvents()
{
    for (int i = 0; i < 9; i++)
    {
        cells[i]->Bind(wxEVT_BUTTON, &GameFrame::OnCellClick, this);
    }
}
void GameFrame::SetStartFrame(wxFrame *startFrame)
{
    this->startFrame = startFrame;
}

void GameFrame::OnCellClick(wxCommandEvent &event)
{
    int id = event.GetId();
    for (int i = 0; i < 9; i++)
    {
        if (cells[i]->GetId() == id)
        {
            game->SetCell(i);
            cells[i]->SetLabelText(game->currentPlayer.type == PlayerType::X ? "X" : "O");
            cells[i]->Disable();
            break;
        }
    }

    game->CheckGameMode();

    if (game->currentCheckType == CheckType::None)
        ChangeTurns();
    else if (game->currentCheckType == CheckType::Draw)
        EndGameWithDraw();
    else
        EndGameWithWin();
}
void GameFrame::ChangeTurns()
{
    game->currentPlayer = game->currentPlayer.type == PlayerType::X ? game->player2 : game->player1;
    std::string player = game->currentPlayer.type == PlayerType::X ? "X" : "O";
    playerText->SetLabelText("Player " + player + " Turn");
}
void GameFrame::EndGameWithDraw()
{
    playerText->SetLabelText("Draw");
    for (int i = 0; i < 9; i++)
    {
        cells[i]->SetBackgroundColour(*wxLIGHT_GREY);

        cells[i]->Disable();
    }
    gameModeText->SetLabelText("The Game End With Draw");
}
void GameFrame::EndGameWithWin()
{
    {
        std::vector<int> winCellsIndex = game->winCellsIndex;
        for (int i = 0; i < winCellsIndex.size(); i++)
        {
            cells[winCellsIndex[i]]->SetBackgroundColour(*wxGREEN);
            cells[winCellsIndex[i]]->SetForegroundColour(*wxBLACK);
        }
        for (int i = 0; i < 9; i++)
        {
            cells[i]->Disable();
        }
        if (game->currentCheckType == CheckType::X)
            gameModeText->SetLabelText("Player X Win"), playerText->SetLabelText("X");
        else
            gameModeText->SetLabelText("Player O Win"), playerText->SetLabelText("O");
    }
}
GameFrame::~GameFrame()
{
    if (game != nullptr)
        delete game;

    std::cout << "GameFrame destructor" << std::endl;
}
