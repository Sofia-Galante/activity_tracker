//
// Created by Sofia Galante on 27/06/19.
//

#include "gtest/gtest.h"
#include "../Activity.h"

TEST(Activity, TestName){
    Activity a;
    a.setName("Nome");
    ASSERT_EQ("Nome", a.getName());
}

TEST(Activity, TestDescription){
    Activity a;
    a.setDescription("Descrizione");
    ASSERT_EQ("Descrizione", a.getDescription());
}

TEST(Activity, TestStartTime){
    Activity a;
    a.setStartTime(20, 10);
    ASSERT_EQ("20:10", a.getStartTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

    a.setStartTime(25, 90);
    ASSERT_EQ("23:59", a.getStartTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

    a.setStartTime(25, 59);
    ASSERT_EQ("23:59", a.getStartTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

    a.setStartTime(23, 80);
    ASSERT_EQ("23:59", a.getStartTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

}

TEST(Activity, TestEndTime){
    Activity a;
    a.setEndTime(20, 10);
    ASSERT_EQ("20:10", a.getEndTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

    a.setEndTime(25, 90);
    ASSERT_EQ("23:59", a.getEndTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

    a.setEndTime(25, 59);
    ASSERT_EQ("23:59", a.getEndTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());

    a.setEndTime(23, 80);
    ASSERT_EQ("23:59", a.getEndTime());
    ASSERT_TRUE(a.getStartTime()<=a.getEndTime());
}

TEST(Activity, TestDate){
    Activity a;
    a.setDate(20, 10, 1999);
    ASSERT_EQ("20/10/1999", a.getDate());

    a.setDate(20, 30, 1999);
    ASSERT_EQ("20/12/1999", a.getDate());

    a.setDate(20, -1, 1999);
    ASSERT_EQ("20/12/1999", a.getDate());

    a.setDate(33, 1, 1999);
    ASSERT_EQ("31/01/1999", a.getDate());

    a.setDate(-2, 1, 1999);
    ASSERT_EQ("31/01/1999", a.getDate());

    a.setDate(-2, -1, 1999);
    ASSERT_EQ("31/12/1999", a.getDate());
}