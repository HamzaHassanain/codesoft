#include "../headers/CropDialog.h"

CropDialog::CropDialog(wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog(parent, id, title)
{
    this->SetClientSize(300, 150);

    label = new wxStaticText(this, wxID_ANY, "Crop From x,y to x,y:");

    topX = new wxTextCtrl(this, wxID_ANY);
    topY = new wxTextCtrl(this, wxID_ANY);
    bottomX = new wxTextCtrl(this, wxID_ANY);
    bottomY = new wxTextCtrl(this, wxID_ANY);

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *horizontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *horizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);

    horizontalSizer1->Add(topX, 1, wxEXPAND | wxALL, 5);
    horizontalSizer1->Add(topY, 1, wxEXPAND | wxALL, 5);

    horizontalSizer2->Add(bottomX, 1, wxEXPAND | wxALL, 5);
    horizontalSizer2->Add(bottomY, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(label, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(horizontalSizer1, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(horizontalSizer2, 0, wxEXPAND | wxALL, 5);

    mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxEXPAND | wxALL, 5);
    this->SetSizer(mainSizer);
}
std::vector<int> CropDialog::GetValue()
{
    int top_x = std::stold(topX->GetValue().ToStdString());
    int top_y = std::stold(topY->GetValue().ToStdString());
    int bottom_x = std::stold(bottomX->GetValue().ToStdString());
    int bottom_y = std::stold(bottomY->GetValue().ToStdString());

    return std::vector<int>{top_x, top_y, bottom_x, bottom_y};
}
