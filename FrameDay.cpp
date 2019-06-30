//
// Created by Sofia Galante on 29/06/19.
//

#include "FrameDay.h"
#include <wx/event.h>

wxBEGIN_EVENT_TABLE(FrameDay, wxFrame)
    EVT_MENU(ID_NEWACTIVITY, FrameDay::newActivity)
    EVT_LIST_ITEM_ACTIVATED(wxID_ANY, FrameDay::modifyActivity)
    EVT_CALENDAR_SEL_CHANGED(wxID_ANY, FrameDay::goToDay)
    EVT_BUTTON(ID_ACTIVITY, FrameDay::newActivity)
wxEND_EVENT_TABLE()

FrameDay::FrameDay(const wxString &title, Register *r)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(530, 700)), logbook(r)
{
    logbook->subscribe(this);

    menubar = new wxMenuBar;
    file = new wxMenu;

    file->Append(ID_NEWACTIVITY, wxT("&Nuova attività"));

    menubar->Append(file, wxT("&File"));
    SetMenuBar(menubar);


    wxPanel *panel = new wxPanel(this, -1);


    calendar = new wxGenericCalendarCtrl(panel, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST);
    list = new wxListCtrl(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    activity = new wxButton(panel, ID_ACTIVITY, wxT("Nuova Attività"));
    dateDay = new wxStaticText(panel, wxID_ANY, wxT("~")+calendar->GetDate().Format("%d/%m/%Y")+wxT("~"));

    list->AppendColumn("Orario di inizio");
    list->AppendColumn("Titolo attività");
    list->SetColumnWidth(0, 150);
    list->SetColumnWidth(1, 350);

    wxBoxSizer *box = new wxBoxSizer(wxVERTICAL);

    box->Add (dateDay, 0, wxTOP | wxCENTER | wxALIGN_CENTRE_VERTICAL, 15);
    box->Add(list, 1, wxALL | wxEXPAND, 15);
    box->Add(calendar, 0, wxALL | wxCENTER, 15);
    box->Add(activity, 0, wxALL | wxALIGN_RIGHT, 15);

    panel->SetSizer(box);

    panel->SetOwnBackgroundColour(*palette.lightestYellow);
    calendar->SetHighlightColours(*wxBLACK, *palette.lightestYellow);
    calendar->SetHeaderColours(*wxBLACK, *palette.lightYellow);
    dateDay->SetFont(*font.title);

    Centre();
}

void FrameDay::newActivity(wxCommandEvent & WXUNUSED(event)) {
    auto frame= new FrameActivity("Nuova attività", logbook, calendar->GetDate().Format("%d/%m/%Y").ToStdString());
    frame->Show(true);
}

void FrameDay::modifyActivity(wxListEvent &event) {
    auto frame = new FrameActivity("Visualizza e modifica attività", logbook, calendar->GetDate().Format("%d/%m/%Y").ToStdString());
    frame->editActivity(activities[event.GetIndex()]);
    frame->Show(true);
}

void FrameDay::goToDay(wxCalendarEvent &event) {
    calendar->SetDate(event.GetDate());
    update();
}

void FrameDay::update() {
    list->ClearAll();
    list->AppendColumn("Orario di inizio");
    list->AppendColumn("Titolo attività");
    list->SetColumnWidth(0, 150);
    list->SetColumnWidth(1, 350);
    auto date = calendar->GetDate();
    dateDay->SetLabelText(wxT("~")+date.Format("%d/%m/%Y")+wxT("~"));
    activities = logbook->GetDailyActivities(date.Format("%d/%m/%Y").ToStdString());
    wxListItem item;
    int i=0;
    for (auto it=activities.begin(); it!=activities.end(); it++){
        item.SetId(i++);
        item.SetColumn(0);
        item.SetText(it->getStartTime());
        list->InsertItem(item);
        item.SetColumn(1);
        item.SetText(it->getName());
        list->SetItem(item);
    }
}