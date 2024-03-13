#include <iostream>
#include <string>
#include "../include/classIllusFriend.h"

using namespace std;

void classIllusFriend::print()
{
    cout << "In class ClassIllusFriend: x = " << x << endl;
}

void classIllusFriend::setX(int a)
{
    x = a;
}

void friendFunc(classIllusFriend cIFObject)
{
    classIllusFriend localTwoObject;

    localTwoObject.x = 45;

    localTwoObject.print();

    cout << "Line 25: in friendFunc accesing "
         << "private member variable "
         << "x = "
         << localTwoObject.x << endl;

    cIFObject.x = 88;
    cIFObject.print();

    cout << "Line 32: in friendFunc accesing "
         << "private member variable "
         << "x = "
         << cIFObject.x << endl;
}