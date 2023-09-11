#include "../../headers/MainFrame.h"

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
