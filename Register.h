//
// Created by Sofia Galante on 22/06/19.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"
#include <map>
#include <iostream>

class Register {
public:

    unsigned long coutDateActivities(std::string date) const{
        return logbook.count(date);
    }

    void saveActivity(const Activity &activity);

    void printDateActivities(const std::string &date);

    void printAllActivities();

    std::multimap<std::string, Activity> getLogbook(){
        return logbook;
    }
    std::multimap<std::string, Activity>::iterator begin(){
        return logbook.begin();
    }
    std::multimap<std::string, Activity>::iterator end(){
        return logbook.end();
    }
private:
    std::multimap<std::string, Activity> logbook;
};

#endif //ACTIVITYTRACKER_REGISTER_H
