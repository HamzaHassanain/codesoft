#include <wx/wx.h>
#include <wx/colordlg.h>
#include <wx/fontdlg.h>
#include "bufferedbitmap.h"
#include "iostream"
#include "vector"
#include "Utils.h"

const std::string ALLOWED_TYPES = "Image Files (*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp";

class MainFrame : public wxFrame
{
    wxImage loadedImage;
    std::vector<wxImage> prevImages;
    BufferedBitmap *staticBitmap;
    wxBitmap bitmap;

    wxPanel *panel;
    wxPanel *buttonsPanel;

    wxButton *loadImageButton;
    wxButton *grayScaleButton;
    wxButton *blurButton;
    wxButton *adjustImageBrightnessButton;
    wxButton *adjustImageContrastButton;
    wxButton *cropImageButton;
    wxButton *resizeImageButton;
    wxButton *saveImageButton;
    wxButton *undoButton;

    wxBoxSizer *sizer;
    wxBoxSizer *panelSizer;
    wxBoxSizer *imageSizer;
    wxBoxSizer *buttonsSizer;

    void InitalizeComponents();
    void InitalizeSizers();
    void BindEvents();

    void OnResize(wxSizeEvent &event);
    void OnLoadImageButtonClick(wxCommandEvent &event);
    void OnGrayScaleButtonClick(wxCommandEvent &event);
    void OnBlurButtonClick(wxCommandEvent &event);
    void OnAdjustImageColorButtonClick(wxCommandEvent &event);
    void OnAdjustImageBrightnessButtonClick(wxCommandEvent &event);
    void OnAdjustImageContrastButtonClick(wxCommandEvent &event);
    void OnCropImageButtonClick(wxCommandEvent &event);
    void OnResizeImageButtonClick(wxCommandEvent &event);
    void OnSaveImageButtonClick(wxCommandEvent &event);
    void OnUndoButtonClick(wxCommandEvent &event);
    void ResizeImageToFit();
    void SetImage();

public:
    MainFrame();
};