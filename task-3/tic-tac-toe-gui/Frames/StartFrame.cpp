#include "StartFrame.h"

StartFrame::StartFrame() : wxFrame(nullptr, wxID_ANY, "Tic Tac Toe")
{

    InitializeComponents();
    SetSizers();
    BindEvents();
}
void StartFrame::InitializeComponents()
{
    wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont buttonsFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    panel = new wxPanel(this);

    title = new wxStaticText(panel, wxID_ANY, "Welcome To Tic Tac Toe Game", wxDefaultPosition, wxSize(400, 50), wxALIGN_CENTER);
    startButtonPlayerVsPlayer = new wxButton(panel, wxID_ANY, "Player Vs Player");
    startButtonPlayerVsComputer = new wxButton(panel, wxID_ANY, "Player Vs Computer");

    title->SetFont(font);
    startButtonPlayerVsPlayer->SetFont(buttonsFont);
    startButtonPlayerVsComputer->SetFont(buttonsFont);
}
void StartFrame::SetSizers()
{
    sizer = new wxBoxSizer(wxVERTICAL);
    panelSizer = new wxBoxSizer(wxVERTICAL);
    buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    panel->SetSizerAndFit(panelSizer);
    this->SetSizerAndFit(sizer);

    panelSizer->Add(title, 1, wxEXPAND | wxTOP, 100);

    panelSizer->Add(buttonsSizer, 1, wxALIGN_CENTER | wxBOTTOM, 100);
    buttonsSizer->Add(startButtonPlayerVsPlayer, 1, wxALIGN_CENTER | wxRIGHT, 50);
    buttonsSizer->Add(startButtonPlayerVsComputer, 1, wxALIGN_CENTER);

    sizer->Add(panel, 1, wxEXPAND);
}
void StartFrame::BindEvents()
{
    startButtonPlayerVsPlayer->Bind(wxEVT_BUTTON, &StartFrame::OnStartButtonPlayerVsPlayerClicked, this);
    startButtonPlayerVsComputer->Bind(wxEVT_BUTTON, &StartFrame::OnStartButtonPlayerVsComputerClicked, this);
}
void StartFrame::SetGameFrame(wxFrame *gameFrame)
{
    this->gameFrame = gameFrame;
}

void StartFrame::OnStartButtonPlayerVsPlayerClicked(wxCommandEvent &evt)
{
    Game *game = new Game();

    GameFrame *gameFrame = new GameFrame(game);

    gameFrame->SetClientSize(400, 600);
    gameFrame->SetStartFrame(this);
    this->SetGameFrame(gameFrame);
    gameFrame->Show(true);
}
void StartFrame::OnStartButtonPlayerVsComputerClicked(wxCommandEvent &evt)
{
}

StartFrame ::~StartFrame()
{

    std::cout << "StartFrame Destroyed" << std::endl;
}