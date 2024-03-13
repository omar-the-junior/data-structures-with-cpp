#include <iostream>
#include "../include/complexType.h"
using namespace std;

int main()
{
     complexType num1(23, 34);
     complexType num2;
     complexType num3;

     cout << "Line 11: Num1 = " << num1 << endl;
     cout << "Line 12: Num2 = " << num2 << endl;

     cout << "Line 11: Enter the complex number "
          << "in the form (a, b): ";
     cin >> num2;

     cout << endl;

     cout << "Line 20: new Value of num2 = "
          << num2 << endl;

     num3 = num1 + num2;

     cout << "Line 25: Num3 = " << num3 << endl;

     cout << "Line 27: " << num1 << " + " << num2
          << " = " << num1 + num2 << endl;

     cout << "Line 30: " << num1 << " * " << num2
          << " = " << num1 * num2 << endl;
     return 0;
}