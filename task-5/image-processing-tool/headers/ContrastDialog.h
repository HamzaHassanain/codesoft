#pragma once

#include <wx/wx.h>

class ContrastDialog : public wxDialog
{
private:
    wxSlider *slider;

public:
    ContrastDialog(wxWindow *parent, wxWindowID id, const wxString &title);
    double GetValue();
};