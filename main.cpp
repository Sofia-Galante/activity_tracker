#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <wx/wx.h>

#include "FrameDay.h"
#include "FrameActivity.h"
#include "Register.h"

class MyApp : public wxApp{
    virtual bool OnInit();
    Register r;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    FrameDay * day=new FrameDay(wxT("Registro"), &r);
    day->Show(true);

    return true;
}