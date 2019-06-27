//
// Created by Sofia Galante on 28/06/19.
//
#include "gtest/gtest.h"
#include "../Activity.h"

class ActivitySuite : public ::testing::Test{
protected:
    virtual void SetUp(){
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

    std::string date;
    Activity a;
};

TEST_F(ActivitySuite, Constructor){
    ASSERT_EQ("Senza titolo", a.getName());
    ASSERT_EQ("Nessuna descrizione inserita", a.getDescription());
    ASSERT_EQ("00:00", a.getStartTime());
    ASSERT_EQ("00:00", a.getEndTime());
    ASSERT_EQ(date, a.getDate());
}