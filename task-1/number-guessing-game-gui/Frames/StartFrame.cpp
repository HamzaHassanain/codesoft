#include "StartFrame.h"

StartFrame::StartFrame() : wxFrame(nullptr, wxID_ANY, "Guess The Number")
{

    InitializeComponents();
    SetSizers();
    BindEvents();
}
void StartFrame::InitializeComponents()
{
    wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    panel = new wxPanel(this);

    title = new wxStaticText(panel, wxID_ANY, "Welcome To Guess The Number Game", wxDefaultPosition, wxSize(400, 50), wxALIGN_CENTER);
    startButton = new wxButton(panel, wxID_ANY, "Start", wxDefaultPosition, wxSize(200, -1));

    title->SetFont(font);
    startButton->SetFont(font);
}
void StartFrame::SetSizers()
{
    sizer = new wxBoxSizer(wxVERTICAL);
    panelSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    panel->SetSizerAndFit(panelSizer);
    this->SetSizerAndFit(sizer);

    panelSizer->Add(title, 1, wxEXPAND | wxTOP, 100);

    panelSizer->Add(buttonSizer, 1, wxALIGN_CENTER | wxBOTTOM, 100);
    buttonSizer->Add(startButton, 1, wxEXPAND);

    sizer->Add(panel, 1, wxEXPAND);
}
void StartFrame::BindEvents()
{
    startButton->Bind(wxEVT_BUTTON, &StartFrame::OnStartButtonClicked, this);
}
void StartFrame::SetGameFrame(wxFrame *gameFrame)
{
    this->gameFrame = gameFrame;
}

void StartFrame::OnStartButtonClicked(wxCommandEvent &evt)
{

    GameFrame *gameFrame = new GameFrame();
    gameFrame->SetClientSize(600, 500);
    gameFrame->SetPosition(wxPoint(100, 100));

    this->SetGameFrame(gameFrame);
    gameFrame->SetStartFrame(this);

    gameFrame->Show(true);

    this->Hide();

    evt.Skip();
}

StartFrame ::~StartFrame()
{
    std::cout << "StartFrame Destroyed" << std::endl;
}