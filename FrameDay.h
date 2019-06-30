//
// Created by Sofia Galante on 29/06/19.
//

#ifndef ACTIVITYTRACKER_FRAMEDAY_H
#define ACTIVITYTRACKER_FRAMEDAY_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/calctrl.h>
#include "FrameActivity.h"
#include "Observer.h"




class FrameDay : public wxFrame, public Observer{
public:
    FrameDay(const wxString &title, Register *logbook);

    void newActivity(wxCommandEvent &event);
    void modifyActivity(wxListEvent &event);
    void goToDay(wxCalendarEvent &event);

    virtual void update() override;

private:
    wxMenuBar *menubar;
    wxMenu *file;
    wxListCtrl *list;
    wxGenericCalendarCtrl *calendar;
    wxButton *activity;
    wxStaticText *dateDay;

    std::vector<Activity> activities;
    Register *logbook;

    wxDECLARE_EVENT_TABLE();
};

const int ID_NEWACTIVITY = 1;
const int ID_ACTIVITY = 2;
#endif //ACTIVITYTRACKER_FRAMEDAY_H
