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
    explicit Activity(std::string name_="Senza titolo");


    void setName(const std::string &name_){
        name=name_;
    }
    void setDescription(const std::string &description_){
        description=description_;
    }
    void setDate(int day_, int month_, int year_);
    void setStartTime (int hour_, int minute_);
    void setEndTime (int hour_, int minute_);

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
