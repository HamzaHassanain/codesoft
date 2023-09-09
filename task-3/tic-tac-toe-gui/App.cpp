#include "Frames/StartFrame.h"
#include "Frames/GameFrame.h"

#include <wx/wx.h>

class App : public wxApp
{
public:
    bool OnInit()
    {

        StartFrame *startFrame = new StartFrame();

        startFrame->SetClientSize(600, 500);

        startFrame->Show(true);

        return true;
    }
};

wxIMPLEMENT_APP(App);