#include <iostream>
#include <string>
#include "../include/rectangleType.h"
using namespace std;

int main()
{
     rectangleType myRectangle(23, 45);
     rectangleType yourRectangle;

     cout << "Line 11: myRectangle: "
          << myRectangle
          << endl;

     cout << "Line 15: Enter the length and width of "
          << "a rectangle: ";
     cin >> yourRectangle;
     cout << endl;

     cout << "Line 20: yourRectangle: "
          << yourRectangle
          << endl;

     cout << "Line 24: myRectangle + yourRectangle: "
          << myRectangle + yourRectangle
          << endl;

     cout << "Line 28: myRectangle * yourRectangle: "
          << myRectangle * yourRectangle
          << endl;

     return 0;
}