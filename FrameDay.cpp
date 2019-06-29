//
// Created by Sofia Galante on 29/06/19.
//

#include "FrameDay.h"

wxBEGIN_EVENT_TABLE(FrameDay, wxFrame)
    EVT_MENU(ID_NEWACTIVITY, FrameDay::newActivity)
wxEND_EVENT_TABLE()

FrameDay::FrameDay(const wxString &title, Register *r)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(500, 700)), logbook(r)
{
    logbook->subscribe(this);

    menubar = new wxMenuBar;
    file = new wxMenu;

    file->Append(ID_NEWACTIVITY, wxT("&Nuova attività"));
    file->Append(wxID_ANY, wxT("&Vai alla data"));
    file->AppendSeparator();

    mod = new wxMenu;
    mod->Append(wxID_ANY, wxT("&Modifica attività"));

    menubar->Append(file, wxT("&File"));
    menubar->Append(mod, wxT("&Modifica"));
    SetMenuBar(menubar);

    Centre();
}

void FrameDay::newActivity(wxCommandEvent & WXUNUSED(event)) {
    auto frame= new FrameActivity("Nuova attività");
    frame->Show(true);
}

void FrameDay::update() {

}

