//
// Created by Sofia Galante on 29/06/19.
//

#ifndef ACTIVITYTRACKER_OBSERVER_H
#define ACTIVITYTRACKER_OBSERVER_H

class Observer {
public:
    virtual ~Observer(){};

    virtual void update() = 0;
};

#endif //ACTIVITYTRACKER_OBSERVER_H
