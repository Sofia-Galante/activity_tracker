//
// Created by Sofia Galante on 29/06/19.
//

#ifndef ACTIVITYTRACKER_FRAMEACTIVITY_H
#define ACTIVITYTRACKER_FRAMEACTIVITY_H

#include <wx/wx.h>
#include "Register.h"

class FrameActivity : public wxFrame{
public:
    FrameActivity(const wxString &title, Register *r);
    void editActivity(const Activity& a){
        activity=a;
        edited=true;
    }

    void refresh(wxShowEvent &event);
    void save(wxCommandEvent &event);

private:
    Activity activity;
    bool edited;
    Register *logbook;

    wxButton *saveButton;
    wxTextCtrl *tc1;
    wxTextCtrl *tc2;
    wxTextCtrl *tc3;
    wxTextCtrl *tc5;

    wxDECLARE_EVENT_TABLE();
};

const int ID_SAVE = 1;

#endif //ACTIVITYTRACKER_FRAMEACTIVITY_H
