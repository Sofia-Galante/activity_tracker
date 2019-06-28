//
// Created by Sofia Galante on 28/06/19.
//

#include "gtest/gtest.h"
#include "../Register.h"
#include "../Activity.h"

TEST(Register, TestSaveActivity){
    Register r;
    Activity a1, a2, a3;

    a1.setName("1");
    a1.setDate(20, 3, 2019);
    a1.setStartTime(22, 30);
    a1.setEndTime(22, 50);
    a1.setDescription("Prima attività");

    a2.setName("2");
    a2.setDate(21, 3, 2019);
    a2.setStartTime(22, 30);
    a2.setEndTime(22, 50);
    a2.setDescription("Seconda attività");

    a3.setName("3");
    a3.setDate(21, 3, 2019);
    a3.setStartTime(23, 30);
    a3.setEndTime(23, 50);
    a3.setDescription("Terza attività");

    r.saveActivity(a3);
    r.saveActivity(a1);
    r.saveActivity(a2);

    auto it=r.begin();
    ASSERT_EQ(it->second, a1);
    it++;
    ASSERT_EQ(it->second, a2);
    it++;
    ASSERT_EQ(it->second, a3);
}

TEST(Register, TestCount){
    Register r;
    Activity a1, a2, a3;

    a1.setName("1");
    a1.setDate(20, 3, 2019);
    a1.setStartTime(22, 30);
    a1.setEndTime(22, 50);
    a1.setDescription("Prima attività");

    a2.setName("2");
    a2.setDate(21, 3, 2019);
    a2.setStartTime(22, 30);
    a2.setEndTime(22, 50);
    a2.setDescription("Seconda attività");

    a3.setName("3");
    a3.setDate(21, 3, 2019);
    a3.setStartTime(23, 30);
    a3.setEndTime(23, 50);
    a3.setDescription("Terza attività");

    r.saveActivity(a3);
    r.saveActivity(a1);
    r.saveActivity(a2);

    std::string date1=a1.getDate();
    std::string date2=a2.getDate();
    std::string date3="20/04/2019";

    ASSERT_EQ(1, r.coutDateActivities(date1));
    ASSERT_EQ(2, r.coutDateActivities(date2));
    ASSERT_EQ(0, r.coutDateActivities(date3));

}
