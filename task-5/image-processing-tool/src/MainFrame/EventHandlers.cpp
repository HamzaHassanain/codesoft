#include <opencv2/opencv.hpp>
#include "../../headers/MainFrame.h"
#include "../../headers/BrightnessDialog.h"
#include "../../headers/BlurDialog.h"
#include "../../headers/ContrastDialog.h"
void MainFrame::BindEvents()
{
    this->Bind(wxEVT_SIZE, &MainFrame::OnResize, this);

    loadImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadImageButtonClick, this);
    grayScaleButton->Bind(wxEVT_BUTTON, &MainFrame::OnGrayScaleButtonClick, this);
    blurButton->Bind(wxEVT_BUTTON, &MainFrame::OnBlurButtonClick, this);
    sharpenButton->Bind(wxEVT_BUTTON, &MainFrame::OnSharpenButtonClick, this);
    adjustImageBrightnessButton->Bind(wxEVT_BUTTON, &MainFrame::OnAdjustImageBrightnessButtonClick, this);
    adjustImageContrastButton->Bind(wxEVT_BUTTON, &MainFrame::OnAdjustImageContrastButtonClick, this);
    cropImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnCropImageButtonClick, this);
    resizeImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnResizeImageButtonClick, this);
    saveImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveImageButtonClick, this);
    undoButton->Bind(wxEVT_BUTTON, &MainFrame::OnUndoButtonClick, this);
}

void MainFrame::OnLoadImageButtonClick(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(this, _("Open Image file"), "", "", ALLOWED_TYPES, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();

    loadedImage = wxImage(filePath);

    prevImages.clear();

    prevImages.push_back(loadedImage.Copy());

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

    BlurDialog dialog(this, wxID_ANY, "Blur");
    if (dialog.ShowModal() == wxID_OK)
    {
        prevImages.push_back(loadedImage.Copy());

        loadedImage = loadedImage.Blur(dialog.GetValue());

        SetImage();
    }
}
void MainFrame::OnGrayScaleButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }
    prevImages.push_back(loadedImage.Copy());

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
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }
    BrightnessDialog dialog(this, wxID_ANY, "Adjust Brightness");
    if (dialog.ShowModal() == wxID_OK)
    {
        prevImages.push_back(loadedImage.Copy());

        int brightness = dialog.GetValue();
        int width = loadedImage.GetWidth();
        int height = loadedImage.GetHeight();

        cv::Mat mat = mat_from_wx(loadedImage);
        cv::Mat new_img = mat + cv::Scalar(brightness, brightness, brightness);

        loadedImage = wx_from_mat(new_img);
        SetImage();
    }
}
void MainFrame::OnAdjustImageContrastButtonClick(wxCommandEvent &event)
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("No image loaded", "Error", wxOK | wxICON_ERROR);
        return;
    }
    ContrastDialog dialog(this, wxID_ANY, "Adjust Contrast");
    if (dialog.ShowModal() == wxID_OK)
    {

        prevImages.push_back(loadedImage.Copy());

        double contrast = dialog.GetValue();
        cv::Mat new_img;
        cv::Mat mat = mat_from_wx(loadedImage);
        mat.convertTo(new_img, -1, contrast, 0);

        loadedImage = wx_from_mat(new_img);

        SetImage();
    }
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

    loadedImage.SaveFile(saveFileDialog.GetPath());
}
void MainFrame::OnUndoButtonClick(wxCommandEvent &event)
{
    loadedImage = prevImages.back();

    if (prevImages.size() > 1)
        prevImages.pop_back();

    SetImage();
}
void MainFrame::OnResize(wxSizeEvent &event)
{
    event.Skip();
}
