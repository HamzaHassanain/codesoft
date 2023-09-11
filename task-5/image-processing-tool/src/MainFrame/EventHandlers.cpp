#include "../../headers/MainFrame.h"
#include <opencv2/opencv.hpp>
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
    cv::Mat mat = mat_from_wx(loadedImage);
    // convert to grayscale
    cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
    // convert back to wxImage
    loadedImage = wx_from_mat(mat);
    SetImage();
}
void MainFrame::OnSharpenButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }
}
void MainFrame::OnAdjustImageColorButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }
    wxColourDialog dialog(this);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxColourData data = dialog.GetColourData();
        wxColour colour = data.GetColour();
        int width = loadedImage.GetWidth();
        int height = loadedImage.GetHeight();

        SetImage();
    }
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
void MainFrame::OnResize(wxSizeEvent &event)
{
    event.Skip();
}