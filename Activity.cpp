//
// Created by Sofia Galante on 22/06/19.
//

#include "Activity.h"

Activity::Activity(std::string name_) : name(name_){

    time_t day = time(nullptr);
    struct tm *t = localtime(&day);
    auto mday = std::to_string(t->tm_mday) ;
    auto month = std::to_string(t->tm_mon+1);
    auto year = std::to_string(t->tm_year);

    date = mday+"/"+month+"/"+year;
    description = "Inserire descrizione";
    startTime = "00:00";
    endTime = "00:00";
}

void Activity::print(){
        std::cout << "Attività: " << name << std::endl << std::endl;
        std::cout << "Descrizione:" << std::endl;
        std::cout << description << std::endl << std::endl;
        std::cout << "Data: " << date << std::endl << std::endl;
        std::cout << "Ora di inizio: " << startTime << std::endl << std::endl;
        std::cout << "Ora di fine: " << endTime << std::endl << std::endl;
    }