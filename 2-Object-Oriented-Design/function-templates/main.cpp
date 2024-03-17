#include <iostream>
#include <string>

using namespace std;

template <class Type>
Type larger(Type x, Type y)
{
     if (x > y)
          return x;
     else
          return y;
}

int main()
{
     cout << "Line 17: Larger of 5 and 6: "
          << larger(5, 6) << endl;

     cout << "Line 20: Larger of A and B: "
          << larger('A', 'B') << endl;

     cout << "Line 23: Larger of 5.6 and 3.2: "
          << larger(5.6, 3.2) << endl;
     string str1 = "Hello";
     string str2 = "Happy";

     cout << "Line 28: Larger of " << str1 << " and " << str2 << ": "
          << larger(str1, str2) << endl;
     return 0;
}