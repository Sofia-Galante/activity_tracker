//
// Created by Sofia Galante on 29/06/19.
//

#include "FrameActivity.h"

wxBEGIN_EVENT_TABLE(FrameActivity, wxFrame)
    EVT_SHOW(FrameActivity::refresh)
    EVT_BUTTON(ID_SAVE, FrameActivity::save)
    EVT_BUTTON(ID_DELETE, FrameActivity::eliminate)
wxEND_EVENT_TABLE()

FrameActivity::FrameActivity(const wxString& framename, Register *r, std::string d)
    : wxFrame(nullptr, wxID_ANY, framename, wxDefaultPosition, wxSize(300, 500)), edited(false), logbook(r), date(d){

    wxPanel *panelbox = new wxPanel(this, -1);
    panelbox->SetOwnBackgroundColour(*palette.lightestYellow);

    wxBoxSizer *box = new wxBoxSizer(wxVERTICAL);

    wxFlexGridSizer *fgs1 = new wxFlexGridSizer(2, 2, 2, 2);
    wxFlexGridSizer *fgs2 = new wxFlexGridSizer(1, 8, 2, 2);
    wxFlexGridSizer *fgs3 = new wxFlexGridSizer(2, 1, 10, 2);

    wxStaticText *title = new wxStaticText(panelbox, -1, wxT("Attività: "));
    wxStaticText *date = new wxStaticText(panelbox, -1, wxT("Data: "));
    wxStaticText *time = new wxStaticText(panelbox, -1, wxT("Orario: "));
    wxStaticText *separateHM1 = new wxStaticText(panelbox, -1, wxT(":"));
    wxStaticText *separateHM2 = new wxStaticText(panelbox, -1, wxT(":"));
    wxStaticText *separatetimes = new wxStaticText(panelbox, -1, wxT("~"));
    wxStaticText *description = new wxStaticText(panelbox, -1, wxT("Descrizione: "));

    txtTitle = new wxTextCtrl(panelbox, -1);
    txtSHour = new wxTextCtrl(panelbox, -1, wxEmptyString, wxDefaultPosition, wxSize(25, -1));
    txtSMinute = new wxTextCtrl(panelbox, -1, wxEmptyString, wxDefaultPosition, wxSize(25, -1));
    txtEHour = new wxTextCtrl(panelbox, -1, wxEmptyString, wxDefaultPosition, wxSize(25, -1));
    txtEMinute = new wxTextCtrl(panelbox, -1, wxEmptyString, wxDefaultPosition, wxSize(25, -1));
    txtDescription = new wxTextCtrl(panelbox, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);
    datepicker = new wxDatePickerCtrl(panelbox, -1);

    fgs1->Add(title);
    fgs1->Add(txtTitle, 3, wxEXPAND);
    fgs1->Add(date);
    fgs1->Add(datepicker, 3, wxEXPAND);
    fgs2->Add(time);
    fgs2->Add(txtSHour, 0);
    fgs2->Add(separateHM1);
    fgs2->Add(txtSMinute, 0);
    fgs2->Add(separatetimes);
    fgs2->Add(txtEHour, 0);
    fgs2->Add(separateHM2);
    fgs2->Add(txtEMinute, 0);
    fgs3->Add(description, 3, wxEXPAND);
    fgs3->Add(txtDescription, 3, wxEXPAND);

    fgs1->AddGrowableCol(1, 1);
    fgs3->AddGrowableRow(1, 1);
    fgs3->AddGrowableCol(0, 1);

    box->Add(fgs1, 0, wxEXPAND | wxALL, 14);
    box->Add(fgs2, 0, wxEXPAND | wxALL, 14);
    box->Add(fgs3, 1, wxEXPAND | wxALL, 14);
    panelbox->SetSizer(box);

    wxBoxSizer *buttonBox = new wxBoxSizer(wxHORIZONTAL);

    deleteButton = new wxButton(panelbox, ID_DELETE, wxT("Elimina"));
    buttonBox->Add(deleteButton, 0, wxALIGN_RIGHT);
    saveButton = new wxButton(panelbox, ID_SAVE, wxT("Salva"));
    buttonBox->Add(saveButton, 0, wxALIGN_RIGHT);

    deleteButton->Hide();

    box->Add(buttonBox, 0, wxEXPAND | wxALL, 14);

    Centre();
}

void FrameActivity::refresh(wxShowEvent &event) {
    if(!edited)
        activity.setDate(date);

    txtTitle->SetLabelText(activity.getName());
    txtDescription->Clear();
    txtDescription->AppendText(activity.getDescription());

    auto shour = activity.getStartTime().std::string::substr(0, 2);
    auto sminute = activity.getStartTime().std::string::substr(3, 2);
    auto ehour = activity.getEndTime().std::string::substr(0, 2);
    auto eminute = activity.getEndTime().std::string::substr(3, 2);
    txtSHour->SetLabelText(shour);
    txtSMinute->SetLabelText(sminute);
    txtEHour->SetLabelText(ehour);
    txtEMinute->SetLabelText(eminute);

    auto day_ = activity.getDate().std::string::substr(0, 2);
    auto month_ = activity.getDate().std::string::substr(3, 2);
    auto year_ = activity.getDate().std::string::substr(6, 4);
    int day = std::stoi(day_);
    int month = std::stoi(month_);
    int year = std::stoi(year_);
    wxDateTime date(wxDateTime::wxDateTime_t(day), wxDateTime::Month(month-1), year, 0, 0);
    datepicker->SetValue(date);
}

void FrameActivity::save(wxCommandEvent &event) {
    if(edited)
        logbook->eraseActivity(activity);

    if(txtTitle->GetValue()==wxEmptyString)
        txtTitle->SetLabelText("Attività senza titolo");
    if(txtDescription->GetValue()==wxEmptyString)
        txtDescription->AppendText("Nessuna descrizione inserita");
    if(txtSHour->GetValue()==wxEmptyString)
        txtSHour->SetLabelText("00");
    if(txtSMinute->GetValue()==wxEmptyString)
        txtSMinute->SetLabelText("00");
    if(txtEHour->GetValue()==wxEmptyString)
        txtEHour->SetLabelText("00");
    if(txtEMinute->GetValue()==wxEmptyString)
        txtEMinute->SetLabelText("00");

    activity.setName(txtTitle->GetValue().ToStdString());
    activity.setDescription(txtDescription->GetValue().ToStdString());
    activity.setDate(datepicker->GetValue().Format("%d/%m/%Y").ToStdString());

    auto ehour = txtEHour->GetValue().ToStdString();
    auto eminute = txtEMinute->GetValue().ToStdString();
    activity.setEndTime(std::stoi(ehour), std::stoi(eminute));

    auto shour = txtSHour->GetValue().ToStdString();
    auto sminute = txtSMinute->GetValue().ToStdString();
    activity.setStartTime(std::stoi(shour), std::stoi(sminute));

    logbook->saveActivity(activity);
    Close();
}

void FrameActivity::eliminate(wxCommandEvent &event) {
    if(wxMessageBox(wxT("Sicuro di voler eliminare l'attività?"), wxT("Attenzione"), wxYES_NO)==wxYES){
        logbook->eraseActivity(activity);
        Close();
    }

}