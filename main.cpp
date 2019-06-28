#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include "Activity.h"
#include "Register.h"

int main() {

    Register r;
    Activity a1;
    Activity a2;
    Activity a3;

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

    Activity A[3]= {a1, a2, a3};

    r.saveActivity(a3);
    r.saveActivity(a1);
    r.saveActivity(a2);


    int i=0;

    for(auto it=r.begin(); it!=r.end(); it++){
        if(A[i]==it->second)
            std::cout << "ok" << std::endl;
        i++;
    }
}