#include <iostream>

using namespace std;

int main()
{
     int *p;
     int *q;

     p = new int;

     *p = 34;
     cout << "Line 13: p = " << p
          << ", *p = " << *p << endl;

     q = p;
     cout << "Line 17: q = " << q
          << ", *q = " << *q << endl;

     *q = 45;
     cout << "Line 21: p = " << p
          << ", *p = " << *p << endl;
     cout << "Line 22: q = " << q
          << ", *q = " << *q << endl;

     p = new int;
     *p = 18;
     cout << "Line 28: p = " << p
          << ", *p = " << *p << endl;
     cout << "Line 30: q = " << q
          << ", *q = " << *q << endl;

     delete q;
     q = NULL;
     q = new int;
     *q = 62;
     cout << "Line 38: p = " << p
          << ", *p = " << *p << endl;
     cout << "Line 40: q = " << q
          << ", *q = " << *q << endl;
     return 0;
}