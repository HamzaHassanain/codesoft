#pragma once

#include <wx/wx.h>
#include "GameFrame.h"
class StartFrame : public wxFrame
{
private:
    wxFrame *gameFrame;
    wxPanel *panel;
    wxStaticText *title;
    wxButton *startButtonPlayerVsPlayer;
    wxButton *startButtonPlayerVsComputer;

    wxSizer *sizer;
    wxSizer *panelSizer;
    wxSizer *buttonsSizer;

    void InitializeComponents();
    void SetSizers();
    void BindEvents();

    void OnStartButtonPlayerVsPlayerClicked(wxCommandEvent &evt);
    void OnStartButtonPlayerVsComputerClicked(wxCommandEvent &evt);

public:
    void SetGameFrame(wxFrame *gameFrame);
    StartFrame();
    ~StartFrame();
};