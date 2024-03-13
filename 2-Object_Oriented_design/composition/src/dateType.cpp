#include <iostream>
#include "../include/dateType.h"

using namespace std;
int dateType::getDay() const
{
    return bDay;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::printDate() const
{
    cout << dMonth << "-" << bDay << "-" << dYear;
}

void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    bDay = day;
    dYear = year;
}

dateType::dateType(int month, int day, int year)
{
    setDate(month, day, year);
}