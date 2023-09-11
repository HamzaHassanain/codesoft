#include "../headers/MainFrame.h"
MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Image Processing Tool")
{
    InitalizeComponents();
    InitalizeSizers();
    BindEvents();
}
