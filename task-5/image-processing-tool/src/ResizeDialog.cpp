#include "../headers/ResizeDialog.h"

ResizeDialog::ResizeDialog(wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog(parent, id, title)
{
    this->SetClientSize(300, 150);

    label = new wxStaticText(this, wxID_ANY, "Resize to:");
    width = new wxTextCtrl(this, wxID_ANY);
    height = new wxTextCtrl(this, wxID_ANY);
    timesLabel = new wxStaticText(this, wxID_ANY, "x");
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

    horizontalSizer->Add(height, 1, wxEXPAND | wxALL, 5);
    horizontalSizer->Add(timesLabel, 0, wxEXPAND | wxALL, 5);
    horizontalSizer->Add(width, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(label, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(horizontalSizer, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxEXPAND | wxALL, 5);
    this->SetSizer(mainSizer);
}
std::vector<int> ResizeDialog::GetValue()
{
    int widthValue = std::stold(width->GetValue().ToStdString());
    int heightValue = std::stold(height->GetValue().ToStdString());

    return std::vector<int>{widthValue, heightValue};
}
