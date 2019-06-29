//
// Created by Sofia Galante on 29/06/19.
//

#ifndef ACTIVITYTRACKER_FRAMEACTIVITY_H
#define ACTIVITYTRACKER_FRAMEACTIVITY_H

#include <wx/wx.h>
#include "Register.h"

class FrameActivity : public wxFrame{
public:
    FrameActivity(const wxString &title);
    void refresh();

    void setActivity(const Activity& a){
        activity=a;
    }

private:
    Activity activity;
    wxButton *save;
    wxTextCtrl *tc1;
    wxTextCtrl *tc2;
    wxTextCtrl *tc3;
    wxTextCtrl *tc5;

    wxDECLARE_EVENT_TABLE();
};

const int ID_TITLE = 1;
const int ID_DATE = 2;
const int ID_STIME = 3;
const int ID_ETIME = 4;
const int ID_DESCR = 5;

#endif //ACTIVITYTRACKER_FRAMEACTIVITY_H
