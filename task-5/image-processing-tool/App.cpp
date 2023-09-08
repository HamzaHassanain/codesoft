#include <wx/wx.h>
#include "MainFrame.h"
class App : public wxApp
{
public:
    bool OnInit()
    {
        MainFrame *frame = new MainFrame();
        frame->SetClientSize(800, 600);
        frame->Maximize(true);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(App);