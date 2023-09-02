#pragma once

#include <wx/wx.h>
#include "GameFrame.h"
class StartFrame : public wxFrame
{
private:
    wxPanel *panel;
    wxStaticText *title;
    wxButton *startButton;

    wxSizer *sizer;
    wxSizer *panelSizer;
    wxSizer *buttonSizer;

    void InitializeComponents();
    void SetSizers();
    void BindEvents();

    void OnKeyPanelDown(wxKeyEvent &evt);

    void OnStartButtonClicked(wxCommandEvent &evt);
    wxFrame *gameFrame;

public:
    void SetGameFrame(wxFrame *gameFrame);
    StartFrame();
    ~StartFrame();
};