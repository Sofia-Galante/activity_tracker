//
// Created by Sofia Galante on 22/06/19.
//

#include "Activity.h"

Activity::Activity()
    : name(""), description(""), startTime("00:00"), endTime("00:00")
{
    time_t today = time(nullptr);
    struct tm *t = localtime(&today);
    auto day = std::to_string(t->tm_mday) ;
    auto month = std::to_string(t->tm_mon+1);
    auto year = std::to_string(t->tm_year+1900);

    if(day.size()!=2)
        day="0"+day;
    if(month.size()!=2)
        month="0"+month;
    date = day+"/"+month+"/"+year;
}

void Activity::setDate(std::string date_) {
    date=date_;
}
void Activity::setStartTime (int hour_, int minute_){
    if(hour_<0 || hour_ >=24)
        hour_=23;
    if(minute_<0 || minute_ >=60)
        minute_=59;
    auto hour=std::to_string(hour_);
    auto minute=std::to_string(minute_);

    if(hour.size()!=2)
        hour="0"+hour;
    if(minute.size()!=2)
        minute="0"+minute;

    startTime = hour+":"+minute;

    if(endTime < startTime){
        endTime=startTime;
    }
}
void Activity::setEndTime (int hour_, int minute_){
    if(hour_<0 || hour_ >=24)
        hour_=23;
    if(minute_<0 || minute_ >=60)
        minute_=59;
    auto hour=std::to_string(hour_);
    auto minute=std::to_string(minute_);

    if(hour.size()!=2)
        hour="0"+hour;
    if(minute.size()!=2)
        minute="0"+minute;

    endTime = hour+":"+minute;

    if(endTime<startTime){
        startTime=endTime;
    }
}

void Activity::print(){
        std::cout << "Attività: " << name << std::endl << std::endl;
        std::cout << "Descrizione:" << std::endl;
        std::cout << description << std::endl << std::endl;
        std::cout << "Data: " << date << std::endl << std::endl;
        std::cout << "Ora di inizio: " << startTime << std::endl << std::endl;
        std::cout << "Ora di fine: " << endTime << std::endl << std::endl;
    }