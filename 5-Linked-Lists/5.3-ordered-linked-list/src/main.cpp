#include <iostream>
#include <string>
#include "../include/orderedLinkedList.h"
using namespace std;

int main()
{
     // * Checkpoint page = 309
     orderedLinkedList<int> list1, list2;
     int num;

     cout << "Line 7: Enter numbers ending "
          << "with -999." << endl;

     cin >> num;

     while (num != -999)
     {
          list1.insert(num);
          cin >> num;
     }

     cout << endl;

     cout << "Line 15: list1: ";
     list1.print();
     cout << endl;

     list2 = list1;

     cout << "Line 19: list2: ";
     list2.print();
     cout << endl;

     cout << "Line 22: Enter the number to be "
          << "deleted: ";
     cin >> num;
     cout << endl;

     list2.deleteNode(num);

     cout << "Line 26: After deleting "
          << num << ", list2: " << endl;
     list2.print();
     cout << endl;

     return 0;
}