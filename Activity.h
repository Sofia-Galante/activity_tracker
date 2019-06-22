//
// Created by Sofia Galante on 22/06/19.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <iostream>
#include <string>
#include <ctime>

class Activity{
public:
    explicit Activity(std::string name_);


    void setName(std::string &name_){
        name=name_;
    }
    void setDescription(std::string &description_){
        description=description_;
    }
    //TODO: aggiungere controllo della validità di giorno e ora + aggiungere giorno della settimana;
    void setDate(std::string &day, std::string &month, std::string &year) {
        date=day+"/"+month+"/"+year;
    }
    void setStartTime (std::string &hour, std::string &minute){
        startTime = hour+":"+minute;
    }
    void setEndTime (std::string &hour, std::string &minute){
        endTime = hour+":"+minute;
    }

    std::string getName() const{
        return name;
    }
    std::string getDescription() const{
        return description;
    }
    std::string getDate() const{
        return date;
    }
    std::string getStartTime() const{
        return startTime;
    }
    std::string getEndTime() const{
        return endTime;
    }

    void print();

private:
    std::string name;
    std::string description;
    std::string date;
    std::string startTime;
    std::string endTime;
};

#endif //ACTIVITYTRACKER_ACTIVITY_H
