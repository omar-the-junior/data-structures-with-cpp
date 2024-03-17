#include <iostream>
#include <string>
#include "../include/unorderedLinkedList.h"
using namespace std;

int main()
{
    unorderedLinkedList<int> list;

    // Add elements to the list
    list.insertLast(10);
    list.insertLast(50);
    list.insertLast(20);
    list.insertLast(52);
    list.insertLast(30);

    // Print the list
    list.print();
    cout << endl;

    // Check if an element is in the list
    if (list.search(20))
        cout << "20 found in the list." << endl;
    else
        cout << "20 not found in the list." << endl;

    // Delete an element from the list
    list.deleteNode(20);

    // Print the list after deletion
    list.print();
    cout << endl;

    return 0;
}