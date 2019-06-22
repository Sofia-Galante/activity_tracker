//
// Created by Sofia Galante on 22/06/19.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"
#include <map>

class Register {
public:

    unsigned long coutActivities(std::string &date) const{
        return registro.count(date);
    }

private:
    std::map<std::string, Activity> registro;
};

#endif //ACTIVITYTRACKER_REGISTER_H
