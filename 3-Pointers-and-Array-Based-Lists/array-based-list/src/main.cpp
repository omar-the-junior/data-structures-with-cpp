#include <iostream>
#include <string>

#include "../include/arrayListType.h"
using namespace std;

int main()
{
    arrayListType<int> intList(100);
    arrayListType<string> stringList;

    int number;

    cout << "List 10: Enter 5 integers: ";

    for (int count = 0; count < 5; count++)
    {
        cin >> number;
        intList.insertAt(count, number);
    }

    cout << endl;

    cout << "List 23: The list you entered is: ";
    intList.print();
    cout << endl;

    cout << "List 27: Enter the item to be deleted: ";
    cin >> number;
    intList.remove(number);
    cout << "Line 30: After removing " << number << " the list is: " << endl;
    intList.print();

    string str;

    cout << "Line 35: Enter 5 strings: ";

    for (int count = 0; count < 5; count++)
    {
        cin >> str;
        stringList.insertAt(count, str);
    }

    cout << endl;

    cout << "Line 45: The list of strings you entered is: ";
    stringList.print();
    cout << endl;

    cout << "Line 49: Enter the string to be deleted: ";
    cin >> str;
    stringList.remove(str);
    cout << "Line 40: After removing " << str << " the list is: " << endl;

    stringList.print();
    cout << endl;
    return 0;
}