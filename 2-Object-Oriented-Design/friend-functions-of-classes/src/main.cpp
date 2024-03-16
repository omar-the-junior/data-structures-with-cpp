#include <iostream>
#include <string>
#include "../include/classIllusFriend.h"

using namespace std;

int main()
{
    classIllusFriend aObject;

    aObject.setX(32);

    cout << "Line 15: aObject.x: ";
    aObject.print();
    cout << endl;

    cout << "*~*~*~* Testing friend function *~*~*~*" << endl
         << endl;

    friendFunc(aObject);

    return 0;
}