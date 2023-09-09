#pragma once
#include "../Game/Game.h"
#include "StartFrame.h"
#include <wx/wx.h>
class GameFrame : public wxFrame
{
private:
    wxFrame *startFrame;
    Game *game;
    wxFont font;
    wxFont buttonsFont;

    wxPanel *panel;
    wxPanel *cellsPanel;
    wxStaticText *gameModeText;
    wxStaticText *playerText;
    std::vector<int> IDList;
    std::vector<wxButton *> cells;

    wxSizer *sizer;
    wxSizer *panelSizer;
    wxSizer *cellsPanelSizer;

    void InitializeComponents();
    void SetSizers();
    void BindEvents();

    void OnCellClick(wxCommandEvent &event);

    void ChangeTurns();
    void EndGameWithWin();
    void EndGameWithDraw();

public:
    void SetStartFrame(wxFrame *startFrame);

    GameFrame(Game *);
    ~GameFrame();
};
