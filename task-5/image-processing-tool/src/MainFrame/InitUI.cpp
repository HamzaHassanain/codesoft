#include "../../headers/MainFrame.h"

void MainFrame::InitalizeComponents()
{
    panel = new wxPanel(this, wxID_ANY);
    buttonsPanel = new wxPanel(panel, wxID_ANY);

    staticBitmap = new BufferedBitmap(panel, wxID_ANY, wxBitmap(wxSize(1, 1)), wxDefaultPosition, FromDIP(wxSize(500, 200)));

    undoButton = new wxButton(buttonsPanel, wxID_ANY, "Undo");
    loadImageButton = new wxButton(buttonsPanel, wxID_ANY, "Load Image");
    grayScaleButton = new wxButton(buttonsPanel, wxID_ANY, "Gray Scale");
    blurButton = new wxButton(buttonsPanel, wxID_ANY, "Blur");
    adjustImageBrightnessButton = new wxButton(buttonsPanel, wxID_ANY, "Adjust Brightness");
    adjustImageContrastButton = new wxButton(buttonsPanel, wxID_ANY, "Adjust Contrast");
    cropImageButton = new wxButton(buttonsPanel, wxID_ANY, "Crop");
    resizeImageButton = new wxButton(buttonsPanel, wxID_ANY, "Resize");
    saveImageButton = new wxButton(buttonsPanel, wxID_ANY, "Save");
}
void MainFrame::InitalizeSizers()
{
    buttonsSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer = new wxBoxSizer(wxHORIZONTAL);
    sizer = new wxBoxSizer(wxHORIZONTAL);

    sizer->Add(panel, 1, wxEXPAND | wxALL, 5);

    buttonsSizer->Add(undoButton, 0, wxALL, 5);
    buttonsSizer->Add(loadImageButton, 0, wxALL, 5);
    buttonsSizer->Add(grayScaleButton, 0, wxALL, 5);
    buttonsSizer->Add(blurButton, 0, wxALL, 5);
    buttonsSizer->Add(adjustImageBrightnessButton, 0, wxALL, 5);
    buttonsSizer->Add(adjustImageContrastButton, 0, wxALL, 5);
    buttonsSizer->Add(cropImageButton, 0, wxALL, 5);
    buttonsSizer->Add(resizeImageButton, 0, wxALL, 5);
    buttonsSizer->Add(saveImageButton, 0, wxALL, 5);

    panelSizer->Add(staticBitmap, 4, wxEXPAND | wxALL, 5);
    panelSizer->Add(buttonsPanel, 1, wxEXPAND | wxALL, 5);

    this->SetSizerAndFit(sizer);
    panel->SetSizerAndFit(panelSizer);
    buttonsPanel->SetSizerAndFit(buttonsSizer);
}