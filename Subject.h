//
// Created by Sofia Galante on 29/06/19.
//

#ifndef ACTIVITYTRACKER_SUBJECT_H
#define ACTIVITYTRACKER_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){};

    virtual void subscribe(Observer * o) = 0;
    virtual void unsubscribe(Observer * o) = 0;
    virtual void notify() = 0;
};

#endif //ACTIVITYTRACKER_SUBJECT_H
