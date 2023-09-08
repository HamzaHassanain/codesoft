#include "./MainFrame/MainFrame.h"

#include <wx/wx.h>

class App : public wxApp
{
public:
    bool OnInit()
    {
        MainFrame *frame = new MainFrame("To Do List");
        frame->SetClientSize(800, 500);
        frame->Center();
        frame->Show(true);

        return true;
    }
};

wxIMPLEMENT_APP(App);