#pragma once

#include <wx/wx.h>

class BlurDialog : public wxDialog
{
private:
    wxSlider *slider;

public:
    BlurDialog(wxWindow *parent, wxWindowID id, const wxString &title);
    int GetValue();
};