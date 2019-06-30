//
// Created by Sofia Galante on 28/06/19.
//

#include "gtest/gtest.h"
#include "../Register.h"
#include "../Activity.h"
#include <string>

class RegisterSuite : public ::testing::Test{
protected:
    virtual void SetUp(){

        a1.setName("1");
        a1.setDate("20/03/2019");
        a1.setStartTime(22, 30);
        a1.setEndTime(22, 50);
        a1.setDescription("Prima attività");

        a2.setName("2");
        a2.setDate("21/03/2019");
        a2.setStartTime(22, 30);
        a2.setEndTime(22, 50);
        a2.setDescription("Seconda attività");

        a3.setName("3");
        a3.setDate("21/03/2019");
        a3.setStartTime(23, 30);
        a3.setEndTime(23, 50);
        a3.setDescription("Terza attività");

        r.saveActivity(a3);
        r.saveActivity(a1);
        r.saveActivity(a2);

    }

    Activity a1, a2, a3;
    Register r;
};



TEST_F(RegisterSuite, TestSaveActivity){
    auto it=r.begin();
    ASSERT_EQ(it->second, a1);
    it++;
    ASSERT_EQ(it->second, a2);
    it++;
    ASSERT_EQ(it->second, a3);
}



TEST_F(RegisterSuite, TestEraseSingleElement){
    r.eraseActivity(a1);
    auto it=r.begin();
    ASSERT_EQ(it->second, a2);
    it++;
    ASSERT_EQ(it->second, a3);
}

TEST_F(RegisterSuite, TestEraseUnknownElement){
    Activity a4;
    r.eraseActivity(a4);
    auto it=r.begin();
    ASSERT_EQ(it->second, a1);
    it++;
    ASSERT_EQ(it->second, a2);
    it++;
    ASSERT_EQ(it->second, a3);
}

TEST_F(RegisterSuite, TestEraseAllAndEraseFromEmptyRegister){
    r.eraseActivity(a1);
    r.eraseActivity(a2);
    r.eraseActivity(a3);
    ASSERT_EQ(r.begin(), r.end());
    r.eraseActivity(a1);
    ASSERT_EQ(r.begin(), r.end());
}