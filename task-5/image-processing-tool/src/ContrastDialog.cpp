#include "../headers/ContrastDialog.h"

ContrastDialog::ContrastDialog(wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog(parent, id, title)
{
    this->SetClientSize(300, 150);
    slider = new wxSlider(this, wxID_ANY, 0, 0, 400, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(slider, 0, wxEXPAND | wxALL, 5);
    sizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL, 5);
    this->SetSizerAndFit(sizer);
}
double ContrastDialog::GetValue()
{
    return slider->GetValue() / 100.0;
}
