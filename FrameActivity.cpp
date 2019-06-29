//
// Created by Sofia Galante on 29/06/19.
//

#include "FrameActivity.h"

wxBEGIN_EVENT_TABLE(FrameActivity, wxFrame)
    EVT_SHOW(FrameActivity::refresh)
    EVT_BUTTON(ID_SAVE, FrameActivity::save)
wxEND_EVENT_TABLE()

FrameActivity::FrameActivity(const wxString& framename, Register *r)
    : wxFrame(nullptr, wxID_ANY, framename, wxDefaultPosition, wxSize(300, 500)), edited(false), logbook(r){

    wxPanel *panelbox = new wxPanel(this, -1);

    wxBoxSizer *box = new wxBoxSizer(wxVERTICAL);

    wxFlexGridSizer *fgs = new wxFlexGridSizer(4, 2, 2, 2);

    wxStaticText *title = new wxStaticText(panelbox, -1, wxT("Attività: "));
    wxStaticText *date = new wxStaticText(panelbox, -1, wxT("Data: "));
    wxStaticText *time = new wxStaticText(panelbox, -1, wxT("Orario: "));
    wxStaticText *description = new wxStaticText(panelbox, -1, wxT("Descrizione: "));

    tc1 = new wxTextCtrl(panelbox, -1);
    tc2 = new wxTextCtrl(panelbox, -1);
    tc3 = new wxTextCtrl(panelbox, -1);
    tc5 = new wxTextCtrl(panelbox, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);

    fgs->Add(title);
    fgs->Add(tc1, 1, wxEXPAND);
    fgs->Add(date);
    fgs->Add(tc2, 1, wxEXPAND);
    fgs->Add(time);
    fgs->Add(tc3, 1);
    fgs->Add(description, 1, wxEXPAND);
    fgs->Add(tc5, 1, wxEXPAND);

    fgs->AddGrowableRow(3, 1);
    fgs->AddGrowableCol(1, 1);

    box->Add(fgs, 1, wxALL | wxEXPAND, 15);
    panelbox->SetSizer(box);

    saveButton = new wxButton(panelbox, ID_SAVE, wxT("Salva"));
    box->Add(saveButton, 0, wxALL, 15);

    Centre();
}

void FrameActivity::refresh(wxShowEvent &event) {
    tc1->SetLabelText(activity.getName());
    tc2->SetLabelText(activity.getDate());
    tc3->SetLabelText(activity.getStartTime());
    tc5->Clear();
    tc5->AppendText(activity.getDescription());
}

void FrameActivity::save(wxCommandEvent &event) {
    if(edited)
        logbook->eraseActivity(activity);
    activity.setName(tc1->GetLabelText().ToStdString());
    activity.setDescription(tc5->GetLabelText().ToStdString());
    logbook->saveActivity(activity);
    Close();
}
