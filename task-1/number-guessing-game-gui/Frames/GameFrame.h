#pragma once
#include "../Game/Game.h"
#include <wx/wx.h>
class GameFrame : public wxFrame
{
private:
    Game *game;
    wxFont font;
    std::vector<int> IDList;

    wxFrame *startFrame;
    wxPanel *lastFeadbackPanel;
    wxPanel *currentNumeberPanel;
    wxPanel *numbersPanel;

    wxStaticText *lastFeedback;
    wxStaticText *currnetNumber;
    std::vector<wxButton *> numbers;
    wxButton *guessButton;

    wxSizer *sizer;
    wxSizer *lastFeadbackPanelSizer;
    wxSizer *currentNumeberPanelSizer;
    wxSizer *numbersPanelSizer;
    wxSizer *numbersSizer;

    void InitializeComponents();
    void SetSizers();
    void BindEvents();

    void OnKeyPanelDown(wxKeyEvent &evt);
    void OnGuessButtonClicked(wxCommandEvent &evt);
    void OnNumbersPanelButtonClicked(wxCommandEvent &evt);

public:
    void SetStartFrame(wxFrame *startFrame);
    std::string GUESS_STRING = "guess...";
    GameFrame();
    ~GameFrame();
};
