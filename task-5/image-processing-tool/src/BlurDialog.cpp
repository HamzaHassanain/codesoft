#include "../headers/BlurDialog.h"

BlurDialog::BlurDialog(wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog(parent, id, title)
{
    this->SetClientSize(300, 150);
    slider = new wxSlider(this, wxID_ANY, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(slider, 0, wxEXPAND | wxALL, 5);
    sizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL, 5);
    this->SetSizerAndFit(sizer);
}
int BlurDialog::GetValue()
{
    return slider->GetValue();
}
