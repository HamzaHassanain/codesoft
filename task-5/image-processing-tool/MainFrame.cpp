#include "MainFrame.h"
const std::string ALLOWED_TYPES = "Image Files (*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp";
MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Image Processing Tool")
{
    InitalizeComponents();
    InitalizeSizers();
    BindEvents();
}
void MainFrame::InitalizeComponents()
{
    panel = new wxPanel(this, wxID_ANY);
    buttonsPanel = new wxPanel(panel, wxID_ANY);

    staticBitmap = new BufferedBitmap(panel, wxID_ANY, wxBitmap(wxSize(1, 1)), wxDefaultPosition, FromDIP(wxSize(500, 200)));

    loadImageButton = new wxButton(buttonsPanel, wxID_ANY, "Load Image");
    grayScaleButton = new wxButton(buttonsPanel, wxID_ANY, "Gray Scale");
    blurButton = new wxButton(buttonsPanel, wxID_ANY, "Blur");
    sharpenButton = new wxButton(buttonsPanel, wxID_ANY, "Sharpen");
    adjustImageColorButton = new wxButton(buttonsPanel, wxID_ANY, "Adjust Color");
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

    buttonsSizer->Add(loadImageButton, 0, wxALL, 5);
    buttonsSizer->Add(grayScaleButton, 0, wxALL, 5);
    buttonsSizer->Add(blurButton, 0, wxALL, 5);
    buttonsSizer->Add(sharpenButton, 0, wxALL, 5);
    buttonsSizer->Add(adjustImageColorButton, 0, wxALL, 5);
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
void MainFrame::BindEvents()
{
    this->Bind(wxEVT_SIZE, &MainFrame::OnResize, this);
    loadImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadImageButtonClick, this);
    grayScaleButton->Bind(wxEVT_BUTTON, &MainFrame::OnGrayScaleButtonClick, this);
    blurButton->Bind(wxEVT_BUTTON, &MainFrame::OnBlurButtonClick, this);
    sharpenButton->Bind(wxEVT_BUTTON, &MainFrame::OnSharpenButtonClick, this);
    adjustImageColorButton->Bind(wxEVT_BUTTON, &MainFrame::OnAdjustImageColorButtonClick, this);
    adjustImageBrightnessButton->Bind(wxEVT_BUTTON, &MainFrame::OnAdjustImageBrightnessButtonClick, this);
    adjustImageContrastButton->Bind(wxEVT_BUTTON, &MainFrame::OnAdjustImageContrastButtonClick, this);
    cropImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnCropImageButtonClick, this);
    resizeImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnResizeImageButtonClick, this);
    saveImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveImageButtonClick, this);
}

void MainFrame::OnLoadImageButtonClick(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(this, _("Open Image file"), "", "", ALLOWED_TYPES, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();

    loadedImage = wxImage(filePath);
    if (!loadedImage.IsOk())
    {
        wxMessageBox("Failed to load image file", "Error", wxOK | wxICON_ERROR);
        return;
    }

    ResizeImageToFit();
}
void MainFrame::OnBlurButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }

    loadedImage = loadedImage.Blur(2);
    SetImage();
}
void MainFrame::OnGrayScaleButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }

    loadedImage = loadedImage.ConvertToGreyscale();
    SetImage();
}
void MainFrame::OnSharpenButtonClick(wxCommandEvent &event)
{
    wxMessageBox("Not implemented yet", "Error", wxOK | wxICON_ERROR);
}
void MainFrame::OnAdjustImageColorButtonClick(wxCommandEvent &event)
{
    wxMessageBox("Not implemented yet", "Error", wxOK | wxICON_ERROR);
}
void MainFrame::OnAdjustImageBrightnessButtonClick(wxCommandEvent &event)
{
    wxMessageBox("Not implemented yet", "Error", wxOK | wxICON_ERROR);
}
void MainFrame::OnAdjustImageContrastButtonClick(wxCommandEvent &event)
{
    wxMessageBox("Not implemented yet", "Error", wxOK | wxICON_ERROR);
}
void MainFrame::OnCropImageButtonClick(wxCommandEvent &event)
{
    wxMessageBox("Not implemented yet", "Error", wxOK | wxICON_ERROR);
}
void MainFrame::OnResizeImageButtonClick(wxCommandEvent &event)
{
    wxMessageBox("Not implemented yet", "Error", wxOK | wxICON_ERROR);
}
void MainFrame::OnSaveImageButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }
    wxFileDialog saveFileDialog(this, _("Save Image file"), "", "", ALLOWED_TYPES, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;
    std::cout << saveFileDialog.GetPath() << std::endl;
    loadedImage.SaveFile(saveFileDialog.GetPath());
}
void MainFrame::ResizeImageToFit()
{
    // to be implemented
    SetImage();
}
void MainFrame::SetImage()
{
    bitmap = wxBitmap(loadedImage);
    staticBitmap->SetBitmap(bitmap);
    staticBitmap->Refresh();
    this->Layout();
}

void MainFrame::OnResize(wxSizeEvent &event)
{
    if (loadedImage.IsOk())
        ResizeImageToFit();
    event.Skip();
}