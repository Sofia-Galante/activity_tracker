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

    unsigned long coutActivities(std::string &date) const{
        return logbook.count(date);
    }

    void saveActivity(const Activity &activity);

    void printDateActivities(const std::string &date);

private:
    std::multimap<std::string, Activity> logbook;
};

#endif //ACTIVITYTRACKER_REGISTER_H
