//
// Created by Sofia Galante on 29/06/19.
//

#ifndef ACTIVITYTRACKER_FRAMEACTIVITY_H
#define ACTIVITYTRACKER_FRAMEACTIVITY_H

#include <wx/wx.h>
#include "Register.h"
#include <wx/datectrl.h>

class FrameActivity : public wxFrame{
public:
    FrameActivity(const wxString &title, Register *r);
    void editActivity(const Activity& a){
        activity=a;
        edited=true;
        deleteButton->Show();
    }

    void refresh(wxShowEvent &event);
    void save(wxCommandEvent &event);
    void eliminate(wxCommandEvent &event);

private:
    Activity activity;
    bool edited;
    Register *logbook;

    wxButton *saveButton;
    wxButton *deleteButton;

    wxTextCtrl *txtTitle;
    wxTextCtrl *txtSHour;
    wxTextCtrl *txtSMinute;
    wxTextCtrl *txtEHour;
    wxTextCtrl *txtEMinute;
    wxTextCtrl *txtDescription;
    wxDatePickerCtrl *datepicker;

    wxDECLARE_EVENT_TABLE();
};

const int ID_SAVE = 1;
const int ID_DELETE = 2;

#endif //ACTIVITYTRACKER_FRAMEACTIVITY_H
