#include "../include/personType.h"
#include <iostream>
#include <string>

using namespace std;

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType::personType()
{
    firstName = "";
    lastName = "";
}

personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}