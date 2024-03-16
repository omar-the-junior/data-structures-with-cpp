#include <iostream>
using namespace std;
#include "../include/rectangleType.h"
#include "../include/boxType.h"
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