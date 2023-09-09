#include "GameFrame.h"
GameFrame::GameFrame() : wxFrame(nullptr, wxID_ANY, "Guess The Number")
{
    // initialize IdList
    for (int i = 0; i < 12; i++)
        IDList.push_back(wxID_LAST + 1 + i);

    game = new Game();
    game->Init();

    InitializeComponents();
    SetSizers();
    BindEvents();
}

void GameFrame::InitializeComponents()
{
    font = wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    lastFeadbackPanel = new wxPanel(this, wxID_ANY);
    currentNumeberPanel = new wxPanel(this, wxID_ANY);
    numbersPanel = new wxPanel(this, wxID_ANY);

    lastFeedback = new wxStaticText(lastFeadbackPanel, wxID_ANY, "Guess A number between 1 and 9999", wxDefaultPosition, wxSize(400, 50), wxALIGN_CENTER);
    currnetNumber = new wxStaticText(currentNumeberPanel, wxID_ANY, GUESS_STRING, wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER);

    guessButton = new wxButton(numbersPanel, wxID_ANY, "Guess", wxDefaultPosition);
    for (int i = 0; i < 10; i++)
    {
        wxButton *button = new wxButton(numbersPanel, IDList[i], std::to_string(i));
        button->SetFont(font);
        numbers.push_back(button);
    }
    numbers.push_back(new wxButton(numbersPanel, IDList[10], "<", wxDefaultPosition));
    numbers.push_back(new wxButton(numbersPanel, IDList[11], "Clear", wxDefaultPosition));

    lastFeedback->SetFont(font);
    currnetNumber->SetFont(font);

    numbers[0]->SetFocus();
}
void GameFrame::SetSizers()
{
    sizer = new wxBoxSizer(wxVERTICAL);

    lastFeadbackPanelSizer = new wxBoxSizer(wxVERTICAL);
    currentNumeberPanelSizer = new wxBoxSizer(wxVERTICAL);
    numbersPanelSizer = new wxBoxSizer(wxVERTICAL);
    numbersSizer = new wxGridSizer(5, 3, 10, 10);

    lastFeadbackPanelSizer->Add(lastFeedback, 1, wxEXPAND);
    currentNumeberPanelSizer->Add(currnetNumber, 1, wxEXPAND);
    for (int i = 0; i < numbers.size(); i++)
        numbersSizer->Add(numbers[i], 1);
    numbersPanelSizer->Add(numbersSizer, 3, wxEXPAND);
    numbersPanelSizer->Add(guessButton, 1, wxEXPAND);

    sizer->Add(lastFeadbackPanel, 1, wxEXPAND | wxTOP, 80);
    sizer->Add(currentNumeberPanel, 1, wxEXPAND | wxTOP | wxBottom, 50);
    sizer->Add(numbersPanel, 2, wxALIGN_CENTER | wxBOTTOM, 100);

    lastFeadbackPanel->SetSizerAndFit(lastFeadbackPanelSizer);
    currentNumeberPanel->SetSizerAndFit(currentNumeberPanelSizer);
    numbersPanel->SetSizerAndFit(numbersPanelSizer);
    this->SetSizerAndFit(sizer);
}

void GameFrame::BindEvents()
{
    guessButton->Bind(wxEVT_BUTTON, &GameFrame::OnGuessButtonClicked, this);
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i]->Bind(wxEVT_BUTTON, &GameFrame::OnNumbersPanelButtonClicked, this);
    }
    this->Bind(wxEVT_KEY_DOWN, &GameFrame::OnKeyPanelDown, this);
}

void GameFrame::SetStartFrame(wxFrame *frame)
{
    startFrame = frame;
}

void GameFrame::OnGuessButtonClicked(wxCommandEvent &evt)
{
    std::string current = currnetNumber->GetLabel().ToStdString();
    if (current == GUESS_STRING)
    {
        wxMessageBox("Please enter a number");
        return;
    }
    int guess = std::stoi(current);
    game->Guess(guess);
    int status = game->GetGuessStatus();
    if (status == 0)
    {
        wxMessageBox("You Guessed The Number Corrcetly!!");

        wxMessageDialog *dialog = new wxMessageDialog(this, "Do you want to play again?", "Play Again", wxYES_NO | wxICON_QUESTION);

        int result = dialog->ShowModal();
        if (result == wxID_YES)
        {
            currnetNumber->SetLabel(GUESS_STRING);
            lastFeedback->SetLabel("Guess A number between 1 and 1000");

            std::string oldString = currnetNumber->GetLabel().ToStdString();
            currentNumeberPanelSizer->Detach(currnetNumber);
            wxDELETE(currnetNumber);
            currnetNumber = new wxStaticText(currentNumeberPanel, wxID_ANY, oldString, wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER);
            currentNumeberPanelSizer->Add(currnetNumber, 1, wxEXPAND);
            currnetNumber->SetFont(font);

            oldString = lastFeedback->GetLabel().ToStdString();
            lastFeadbackPanelSizer->Detach(lastFeedback);
            wxDELETE(lastFeedback);
            lastFeedback = new wxStaticText(lastFeadbackPanel, wxID_ANY, oldString, wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER);
            lastFeadbackPanelSizer->Add(lastFeedback, 1, wxEXPAND);
            lastFeedback->SetFont(font);

            game->Reset();
            return;
        }
        else
            this->Close(true);
    }
    else if (status == -1)
        lastFeedback->SetLabel(std::to_string(guess) + " Is Low");
    else
        lastFeedback->SetLabel(std::to_string(guess) + " Too High");

    std::string oldString = lastFeedback->GetLabel().ToStdString();
    lastFeadbackPanelSizer->Detach(lastFeedback);
    wxDELETE(lastFeedback);
    lastFeedback = new wxStaticText(lastFeadbackPanel, wxID_ANY, oldString, wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER);
    lastFeadbackPanelSizer->Add(lastFeedback, 1, wxEXPAND);
    lastFeedback->SetFont(font);
    return;
}
void GameFrame::OnNumbersPanelButtonClicked(wxCommandEvent &evt)
{

    if (currnetNumber)
    {
    }
    else
    {
        std::cout << "currnetNumber is null" << std::endl;
        return;
    }
    int clear = IDList[11];
    int back = IDList[10];

    int caller = evt.GetId();
    if (caller == clear)
    {
        currnetNumber->SetLabel(GUESS_STRING);
        goto end;
    }
    if (caller == back)
    {
        std::string current = currnetNumber->GetLabel().ToStdString();

        if (current == GUESS_STRING)
            goto end;

        if (current.size() > 0)
        {
            current.pop_back();
            currnetNumber->SetLabel(current);
        }
        if (current.size() == 0)
            currnetNumber->SetLabel(GUESS_STRING);
        goto end;
    }
    if (currnetNumber->GetLabel() != GUESS_STRING and currnetNumber->GetLabel().size() == 4)
    {
        wxMessageBox("You can't enter more than 4 digits");
        goto end;
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        if (caller == numbers[i]->GetId())
        {
            std::string current = currnetNumber->GetLabel().ToStdString();
            if (current == GUESS_STRING)
                current = "";
            current += numbers[i]->GetLabel().ToStdString();
            currnetNumber->SetLabel(current);
            goto end;
        }
    }
end:

    std::string oldString = currnetNumber->GetLabel().ToStdString();
    currentNumeberPanelSizer->Detach(currnetNumber);
    wxDELETE(currnetNumber);
    currnetNumber = new wxStaticText(currentNumeberPanel, wxID_ANY, oldString, wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER);
    currentNumeberPanelSizer->Add(currnetNumber, 1, wxEXPAND);
    currnetNumber->SetFont(font);
    return;
}
void GameFrame::OnKeyPanelDown(wxKeyEvent &evt)
{
    std::cout << evt.GetKeyCode() << std::endl;
}
GameFrame ::~GameFrame()
{
    std::cout << "GameFrame Destroyed" << std::endl;
    if (game)
        delete game;
    if (startFrame)
        startFrame->Show(true);
}
