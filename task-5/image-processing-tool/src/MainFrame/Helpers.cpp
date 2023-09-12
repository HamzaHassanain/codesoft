#include "../../headers/MainFrame.h"

void MainFrame::ResizeImageToFit()
{
    // to be implemented
    SetImage();
}
void MainFrame::SetImage()
{
    if (!loadedImage.IsOk())
    {
        wxMessageBox("Bad Image or No image found", "Error", wxOK | wxICON_ERROR);
        return;
    }
    bitmap = wxBitmap(loadedImage);
    staticBitmap->SetBitmap(bitmap);
    staticBitmap->Refresh();
    this->Layout();
}
