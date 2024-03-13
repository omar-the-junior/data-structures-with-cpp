#include <iostream>
#include <string>

#include "../include/personalInfoType.h"
#include "personType.cpp"
#include "dateType.cpp"

using namespace std;

void personalInfoType::setPersonalInfo(string first, string last, int month, int day, int year, int id)
{
    name.setName(first, last);
    bDay.setDate(month, day, year);
    personId = id;
}

void personalInfoType::printPerfonalInfo() const
{
    name.print();
    cout << "'s date of birth is ";
    bDay.printDate();
    cout << endl;
    cout << "and personal ID is " << personId;
}

personalInfoType::
    personalInfoType(string first, string last,
                     int month, int day, int year,
                     int id) : name(first, last),
                               bDay(month, day, year)
{
    personId = id;
}