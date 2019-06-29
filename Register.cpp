//
// Created by Sofia Galante on 22/06/19.
//

#include "Register.h"

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
}

void Register::printDateActivities(const std::string &date) {
    std::pair <std::multimap <std::string, Activity>::iterator, std::multimap <std::string, Activity>::iterator> key;
    key = logbook.equal_range(date);
        for(auto it=key.first; it!=key.second; it++){
            it->second.print();
        }
}

void Register::printAllActivities() {
    for(auto it=logbook.begin(); it!=logbook.end(); it++){
        it->second.print();
    }
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