//
// Created by Sofia Galante on 22/06/19.
//

#include "Register.h"
#include <fstream>

void Register::saveActivity(const Activity &activity) {
    auto key = logbook.equal_range(activity.getDate());
    if(key.first==key.second)
        logbook.insert(std::pair<std::string, Activity> (activity.getDate(), activity));
    else{
        auto correctPlace=key.first;
        for (auto it=key.first; it!=key.second; it++) {
            if(it->second.getStartTime() < activity.getStartTime()){
                correctPlace=it;
            }
        }

        if(!(activity.getStartTime() < key.first->second.getStartTime())){
            correctPlace++;
        }
        logbook.insert(correctPlace, std::pair<std::string, Activity> (activity.getDate(), activity) );
    }

    notify();
}

void Register::eraseActivity(const Activity &activity) {
    auto key = logbook.equal_range(activity.getDate());
    for(auto it=key.first; it!=key.second; it++){
        if(it->second==activity){
            logbook.erase(it);
            notify();
            break;
        }
    }

}

std::vector<Activity> Register::GetDailyActivities(const std::string &date) {
    auto key = logbook.equal_range(date);
    std::vector<Activity> vector;
    for (auto it=key.first; it!=key.second; it++){
        vector.push_back(it->second);
    }
    return vector;
}

void Register::subscribe(Observer *o) {
    observers.push_back(o);
}
void Register::unsubscribe(Observer *o) {
    observers.remove(o);
}
void Register::notify() {
    for(auto it=observers.begin(); it!=observers.end(); it++){
        (*it)->update();
    }
}