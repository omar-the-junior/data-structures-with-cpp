#ifndef PERSONALINFOTYPE_H
#define PERSONALINFOTYPE_H

#include <string>
#include "personType.h"
#include "dateType.h"
using namespace std;
class personalInfoType
{
private:
    personType name;
    dateType bDay;
    int personId;

public:
    void setPersonalInfo(string first, string last, int month, int day, int year, int id);
    void printPerfonalInfo() const;
    personalInfoType(string first = "", string last = "", int month = 1, int day = 1, int year = 2024, int id = 0);
};
#endif