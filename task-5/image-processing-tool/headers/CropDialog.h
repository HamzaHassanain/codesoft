#pragma once

#include <wx/wx.h>

class CropDialog : public wxDialog
{
private:
    wxStaticText *label;
    wxTextCtrl *topX, *topY, *bottomX, *bottomY;

public:
    CropDialog(wxWindow *parent, wxWindowID id, const wxString &title);
    std::vector<int> GetValue();
};