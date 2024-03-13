#include <iostream>
#include <string>
#include "../include/personType.h"

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

personType &personType::setFirstName(string first)
{
    firstName = first;
    // * using `*this` means dereferencing the pointer to the object
    // * this returns the object itself instead of a pointer to the object
    return *this;
}

personType &personType::setLastName(string last)
{
    lastName = last;
    return *this;
}

personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}