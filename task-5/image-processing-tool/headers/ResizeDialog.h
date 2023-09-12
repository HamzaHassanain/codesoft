#pragma once

#include <wx/wx.h>

class ResizeDialog : public wxDialog
{
private:
    wxTextCtrl *width;
    wxTextCtrl *height;
    wxStaticText *label;
    wxStaticText *timesLabel;

public:
    ResizeDialog(wxWindow *parent, wxWindowID id, const wxString &title);
    std::vector<int> GetValue();
};