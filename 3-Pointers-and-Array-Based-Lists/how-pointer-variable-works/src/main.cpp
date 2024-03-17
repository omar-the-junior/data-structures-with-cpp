#include <iostream>
#include <string>

using namespace std;

int main()
{
     int *p;
     int num1 = 5;
     int num2 = 8;

     p = &num1;
     cout << "Lint 13: &num1 = " << &num1
          << ", p = " << p << endl;
     cout << "Line 15: num1 = " << num1
          << ", *p = " << *p << endl;

     *p = 10;
     cout << "Line 19: num1 = " << num1
          << ", *p = " << *p << endl;
     p = &num2;

     cout << "Line 23: &num2 = " << &num2
          << ", p = " << p << endl;

     cout << "Line 26: num2 = " << num2
          << ", *p = " << *p << endl;

     *p = 2 * (*p);
     cout << "Line 30: num2 = " << num2
          << ", *p = " << *p << endl;
     return 0;
}