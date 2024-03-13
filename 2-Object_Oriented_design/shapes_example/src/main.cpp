#include <iostream>
using namespace std;
#include "rectangleType.cpp"
#include "boxType.cpp"
// ------------------------------------------------ new boxType class ------------------------------------------------

int main()
{
    rectangleType myRectangle(5.0, 3.0);
    boxType myBox(6.0, 5.0, 4.0);

    myRectangle.print();
    cout << endl;
    myBox.print();
    cout << endl;
    return 0;
}