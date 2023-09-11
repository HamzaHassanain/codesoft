#pragma once

#include <wx/wx.h>

class BrightnessDialog : public wxDialog
{
private:
    wxSlider *slider;

public:
    BrightnessDialog(wxWindow *parent, wxWindowID id, const wxString &title);
    double GetValue();
};