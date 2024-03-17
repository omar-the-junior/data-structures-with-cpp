#include <iostream>
#include <string>
#include "../include/personType.h"

using namespace std;

int main()
{
    personType student1("Mohammed", "Khaled");
    personType student2;
    personType student3;

    cout << "Line 13: student1: ";
    student1.print();
    cout << endl;
    student2.setFirstName("Omar").setLastName("Masoud");

    cout << "Line 18: -- student2 --";
    student2.print();
    cout << endl;

    student3.setFirstName("Ahmed");

    cout << "Line 22: -- student3 --";
    student3.print();
    cout << endl;

    student3.setLastName("Ali");

    cout << "Line 30: -- student3 --";
    student3.print();
    cout << endl;

    return 0;
}