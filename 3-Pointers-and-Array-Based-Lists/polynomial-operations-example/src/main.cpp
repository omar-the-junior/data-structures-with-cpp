#include <iostream>
#include <string>
#include "../include/polynomialType.h"
using namespace std;

int main()
{
     polynomialType p(8);
     polynomialType q(4);
     polynomialType t;

     cin >> p;
     cout << endl
          << "Line 13: p(x): " << p << endl;

     cout << "Line 16: p(5): " << p(5)
          << endl
          << endl;

     cin >> q;
     cout << endl
          << "Line 18: q(x): " << q << endl
          << endl;

     cout << "Line 25: q(5): " << q(5)
          << endl
          << endl;
     t = p + q;

     cout << "Line 24: p(x) + q(x): " << t << endl;

     cout << "Line 26: p(x) - q(x): " << p - q << endl;
     return 0;
}